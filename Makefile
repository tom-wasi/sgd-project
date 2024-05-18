all:
	g++ -I src/include -L src/lib -o main main.cpp TextureManager.cpp Player.cpp Enemy.cpp Input.cpp EnemyService.cpp GameObject.cpp Game.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image