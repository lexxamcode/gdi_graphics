#include <windows.h>
#include <random>

void draw_painting(HWND h)
{
    //Get context
    HDC dc = GetDC(h);

    //Brushes
    HBRUSH soft_red = CreateSolidBrush(RGB(186, 54, 47));
    HBRUSH yellow = CreateSolidBrush(RGB(250, 189, 85));
    HBRUSH moonlight = CreateSolidBrush(RGB(244, 245, 203));
    HBRUSH light_green = CreateSolidBrush(RGB(146, 186, 138));
    HBRUSH green = CreateSolidBrush(RGB(51, 82, 45));
    HBRUSH dark_green = CreateSolidBrush(RGB(20, 28, 19));
    HBRUSH black = CreateSolidBrush(RGB(0, 0, 0));
    HBRUSH dark_wood = CreateSolidBrush(RGB(69, 48, 40));
    HBRUSH wood = CreateSolidBrush(RGB(51, 47, 45));
    HBRUSH dark_sky = CreateSolidBrush(RGB(37, 48, 69));
    HBRUSH light_wood = CreateSolidBrush(RGB(54, 51, 49));
    HBRUSH dirt = CreateSolidBrush(RGB(38, 28, 25));
    //

    // *******************************
    // *     Painting background     *
    // *******************************
    SelectObject(dc, dark_sky);
    Rectangle(dc, 0, 0, 800, 600); //Sky

    POINT stars[100];
    SelectObject(dc, moonlight);
    for (size_t i = 0; i < 100; i++)
    {
        stars[i] = {0 + rand()%800, 425-(rand()%425)};
        Ellipse(dc, stars[i].x, stars[i].y, stars[i].x+5, stars[i].y+5);
    }


    SelectObject(dc, moonlight);
    Ellipse(dc, 250, 200, 350, 300); //Moon

    SelectObject(dc, light_green); // Trees and bushes behind house
    Ellipse(dc, -50, 100, 100, 500);
    Ellipse(dc, 0, 110, 150, 510);

    Ellipse(dc, 230, 275, 330, 500);
    Ellipse(dc, 250, 250, 430, 550);

    Ellipse(dc, 600, 400, 625, 425);
    Ellipse(dc, 850, 100, 600, 500);

    SelectObject(dc, dark_green);
    Rectangle(dc, 0, 425, 800, 600);//Ground

    // ***************************
    // *     Painting apples     *
    // ***************************
    SelectObject(dc, soft_red); //Far apples
    Ellipse(dc, 100, 200, 125, 225);
    Ellipse(dc, 70, 220, 95, 245);
    Ellipse(dc, 110, 300, 135, 325);
    Ellipse(dc, 40, 150, 65, 175);

    Ellipse(dc, 700, 200, 675, 225);
    Ellipse(dc, 670, 130, 695, 155);
    Ellipse(dc, 750, 120, 725, 145);
    Ellipse(dc, 600, 300, 625, 325);
    Ellipse(dc, 590, 320, 615, 345);

    // *************************
    // *     Painting home     *
    // *************************
    POINT house[3] = {{200, 450}, {400, 100}, {600, 450}}; //Roof and wall
    SelectObject(dc, wood); Polygon(dc, house, 3);

    house[0] = {225, 450};
    house[1] = {400, 150};
    house[2] = {575, 450};
    SelectObject(dc, dark_wood); Polygon(dc, house, 3);

    SelectObject(dc, light_wood);
    Rectangle(dc, 315, 450, 400, 300); //Door
    SelectObject(dc, wood);
    Ellipse(dc, 375, 385, 390, 370); //Door handle

    SelectObject(dc, light_wood);
    Rectangle(dc, 408, 298, 487, 402); //Window frame

    SelectObject(dc, yellow);
    Rectangle(dc, 410, 400, 485, 300); //Window
    SelectObject(dc, light_wood);
    Rectangle(dc, 438, 300, 445, 400);
    Rectangle(dc, 410, 325, 438, 332);

    SelectObject(dc, dark_wood); //Supports
    Rectangle(dc, 225, 475, 250, 450);
    Rectangle(dc, 575, 475, 550, 450);

    SelectObject(dc, wood);//Stairs
    Rectangle(dc, 300, 465, 415, 450);
    Rectangle(dc, 295, 460, 420, 475);

    SelectObject(dc, dirt);
    POINT way[4] = {{300, 475}, {415, 475}, {500, 600}, {200, 600}};
    Polygon(dc, way, 4);

    // *******************************
    // *     Painting foreground     *
    // *******************************
    SelectObject(dc, green);
    Ellipse(dc, -150, 200, 100, 650); //Trees and bushes on foreground
    Ellipse(dc, -100, 350, 250, 650);

    Ellipse(dc, 850, 225, 600, 600);
    Ellipse(dc, 900, 350, 700, 650);

    SelectObject(dc, dark_green);
    Ellipse(dc, -150, 400, 100, 650); //Close foreground
    Ellipse(dc, 0, 475, 350, 650);
    Ellipse(dc, 0, 450, 125, 650);
    Ellipse(dc, 900, 400, 600, 650);
    Ellipse(dc, 900, 450, 725, 650);

    SelectObject(dc, soft_red);
    Ellipse(dc, 750, 300, 780, 330);//Close apples
    Ellipse(dc, 650, 350, 680, 380);
    Ellipse(dc, 600, 400, 630, 430);
    Ellipse(dc, 650, 250, 680, 280);

    Ellipse(dc, 100, 350, 130, 380);
    Ellipse(dc, 150, 430, 180, 460);
    POINT grass[82];

    for (size_t i = 0; i < 80; i++)
        grass[i] = {(LONG)i*10, LONG(600 - (rand()%100 + 50))};
    grass[80] = {800, 650};
    grass[81] = {0, 650};
    SelectObject(dc, black);
    Polygon(dc, grass, 82);

    //Delete brushes
    DeleteObject(soft_red); DeleteObject(yellow); DeleteObject(moonlight); DeleteObject(light_green);
    DeleteObject(green); DeleteObject(dark_green); DeleteObject(black); DeleteObject(dark_wood);
    DeleteObject(light_wood); DeleteObject(dark_sky); DeleteObject(wood);
    DeleteObject(dirt);


    //Delete context
    ReleaseDC(h, dc); DeleteDC(dc);
}

LONG WINAPI WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    HDC hdc;
    HDC memDC;
    HBITMAP memBM;
    PAINTSTRUCT ps;
    HANDLE hOld;
    switch(message)
    {
        case WM_PAINT: // With double buffering
            hdc = BeginPaint(hwnd, &ps);
            memDC = CreateCompatibleDC(hdc);
            memBM = CreateCompatibleBitmap(hdc, 800, 600);
            hOld = SelectObject(memDC, memBM);
            draw_painting((HWND)memDC);
            BitBlt(hdc, 0, 0, 800, 600, memDC, 0, 0, SRCCOPY);
            SelectObject(memDC, hOld);
            DeleteObject(memBM);
            DeleteDC(memDC);
            draw_painting(hwnd);
            EndPaint(hwnd, &ps);
            break;
        case WM_ERASEBKGND:
            return 1;
        case WM_KEYDOWN:
            if (wparam == VK_ESCAPE) PostQuitMessage(0);
            break;
        case WM_LBUTTONDOWN:
            if ((LOWORD(lparam) < 20) && (LOWORD(lparam) < 20)) PostQuitMessage(0);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcA(hwnd, message, wparam, lparam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG message;
    WNDCLASS main_window;
    memset(&main_window, 0, sizeof(WNDCLASS));

    main_window.style = CS_HREDRAW | CS_VREDRAW;
    main_window.lpfnWndProc = reinterpret_cast<WNDPROC>(WndProc);
    main_window.hInstance = hInstance;
    main_window.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    main_window.lpszClassName = "main window";
    RegisterClass(&main_window);

    HWND main_hwnd = CreateWindow("main window", "\"House in da woods\" - Alexey Mishkin 6311",
                                  WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);

    ShowWindow(main_hwnd, nCmdShow);
    UpdateWindow(main_hwnd);
    draw_painting(main_hwnd);
    while (GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return message.wParam;

}
