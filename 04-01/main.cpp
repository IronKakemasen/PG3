#include <Novice.h>
#include <vector>
#include <memory>
#include <unordered_map>

const char kWindowTitle[] = "学籍番号";

enum Type
{
	kTitle,
	kInGame,
	kClear,

	kCount
};

// キー入力結果を受け取る箱
char keys[256] = { 0 };
char preKeys[256] = { 0 };

Type next = kInGame;

struct Enemy
{
	float hp = 1;
};

struct Player
{
	float b = 1;
};

struct Scene
{
	virtual void Run() = 0;
};

struct Title  : public Scene
{
	virtual void Run()override 
	{
		if (keys[DIK_0])
		{
			next = kInGame;

		}
	}
};

struct InGame : public Scene
{
	Player p;
	Enemy e;

	virtual void Run()override 
	{

		if (keys[DIK_0])
		{
			e.hp -= p.b;
			if (e.hp <= 0.0f)
			{
				next = kTitle;

			}

		}
	};
};

struct Clear : public Scene
{
	virtual void Run()override {};
};



struct SceneManager
{

	std::unordered_map<Type,std::unique_ptr<Scene>> sceneContainer;
	static inline Scene* cur;

	SceneManager()
	{
		sceneContainer[kTitle] = std::make_unique<Title>();
		sceneContainer[kInGame] = std::make_unique<InGame>();
		sceneContainer[kClear] = std::make_unique<Clear>();

		cur = sceneContainer[kInGame].get();

	}

};





// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	SceneManager s;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		s.cur->Run();

		s.cur = s.sceneContainer[next].get();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
