/**
* @file CMemTest.cpp
* @brief メモリリークテスト用
* @author 横山明央
* @date 2019/05/29
* @details メモリリークテストとポインタの練習
*/

#define _CRTDBG_MAP_ALLOC
#include <malloc.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "pch.h"
#include <iostream>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__ )
#else
#define DBG_NEW new
#endif


/**
* @brief ポイントデータ
* @details ポイントのデータ構造
*/
struct PointData {
	//! x座標
	int x;
	//! y座標
	int y;
	//! z座標
	int z;
};

/**
* @brief キャラクターデータ
* @details キャラクターのステータスのstruct
*/
struct CharacterData {
	char name[100];
	int hp;
	int mp;
};

/**
* @brief メイン関数
* @param[in] a(元の値) 計算する元の数値
* @param[out] b(代入先) 計算結果を代入する先
* @return int 0を返す
* @details メモリリークのテストとポインタの練習
*/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 160;
	PointData *pPointData = DBG_NEW PointData;
	delete pPointData;
	for (int i = 0; i < 50; ++i) {
		pPointData = DBG_NEW PointData;
		delete pPointData;

	}
	_RPT0(_CRT_WARN, "Set Break Point\n");

	CharacterData *pCharacterData = DBG_NEW CharacterData;
	delete pCharacterData;
	for (int i = 0; i < 50; ++i) {
		pCharacterData = DBG_NEW CharacterData;
		delete pCharacterData;

	}


	char *p = (char*)_alloca(100);
	char **p2 = &p;
	**p2 = 'q';

	char *_p = p;
	for (int i = '0'; i <= 'x'; ++i) {
		*_p++ = i;
	}

	_CrtDumpMemoryLeaks();

	return 0;
}

<<<<<<< HEAD
//村上春樹　1949/1/12 
//著書　ノルウェイの森　海辺のカフカ
=======
//	横山明央 07/03/2019
>>>>>>> origin/master
