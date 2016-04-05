/**
 * Description : Rectangle Area
 *               Find the total area covered by two rectilinear rectangles in a
 *               2D plane. Each rectangle is defined by its bottom left corner
 *               and top right corner.
 * Author      : Evan Lau
 * Date        : 2016/04/05
 */

#include <stdio.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int area1 = (C - A) * (D - B);
    int area2 = (G - E) * (H - F);
    int area3 = 0;

    // bottom left
    int x1 = MAX(A,E);
    int y1 = MAX(B,F);

    // top right
    int x2 = MIN(C,G);
    int y2 = MIN(D,H);

    if ((x2 - x1 > 0) && (y2 - y1 > 0))
    {
        area3 = (x2 - x1) * (y2 - y1);
    }

    if (area3 > area1 || area3 > area2)
        area3 = 0;

    return area1 + area2 - area3;
}

int main(void)
{
    printf("%d\n", computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
    printf("%d\n", computeArea(-1500000001, 0, -1500000000, 1,
                               1500000000, 0, 1500000001, 1));

    return 0;
}
