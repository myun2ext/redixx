#include <windows.h>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow){

	HWND hwnd;
	MSG  msg;
	WNDCLASSEX  wndclass ;

	wndclass.cbSize        = sizeof(wndclass);        /* 構造体の大きさ */
	wndclass.style         = CS_HREDRAW | CS_VREDRAW; /* スタイル */
	wndclass.lpfnWndProc   = WndProc;                /* メッセージ処理関数 */
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.hInstance     = hInstance;             /* プログラムのハンドル */
	wndclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION); /* アイコン */
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);     /* カーソル */
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); /* ブラシ */
	wndclass.lpszMenuName  = NULL;              /* メニュー */
	wndclass.lpszClassName = "Test Window";   /* クラス名 */
	wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass); /* ウインドウクラスTest Windowを登録 */

	hwnd = CreateWindow (
           "Test Window",        /* ウインドウクラス名 */
	   	    "窓を開く",           /* ウインドウのタイトル */
            WS_OVERLAPPEDWINDOW, /* ウインドウスタイル */
            32,32,               /* ウインドウ表示位置 */
            256,256,             /* ウインドウの大きさ */
            NULL,                /* 親ウインドウのハンドル */
            NULL,                /* メニューのハンドル */
            hInstance,           /* インスタンスのハンドル */
            NULL);               /* 作成時の引数保存用ポインタ */

	ShowWindow (hwnd,iCmdShow);      /* ウインドウを表示 */
	UpdateWindow (hwnd);

	while (GetMessage (&msg,NULL,0,0)) { /* メッセージループ */

		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return msg.wParam ;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {

	switch (iMsg) {

		case WM_DESTROY : /* 終了処理 */

			PostQuitMessage(0);
			return 0;

	}

	return DefWindowProc (hwnd, iMsg, wParam, lParam) ;

}
