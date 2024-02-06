#include<stdio.h>
#include<math.h>
#define MAX_POINTS 10

typedef struct {
    double x;
    double y;
} Point;

double clcd(Point p1, Point p2) 
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main()
 {
    int npoint;
    printf("Enter the number of points up to %d ", MAX_POINTS);
    scanf("%d", &npoint);

    if (npoint <= 0 || npoint > MAX_POINTS) 
    {
        printf("Invalid number of points.\n");
        return 1;
    }

Point points[MAX_POINTS];
    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < npoint; i++) {
        printf("enter Point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double distance_matrix[MAX_POINTS][MAX_POINTS];
    printf("\nDistance Matrix:\n");
    for (int i = 0; i < npoint; i++) {

        for (int j = 0; j < npoint; j++) 
        {

            distance_matrix[i][j] = clcd(points[i], points[j]);
            printf("%.2lf\t", distance_matrix[i][j]);
        }
        printf("\n");
    }
    double m=distance_matrix[0][0];
    printf("the minimum distance coordiantes are");
    for (int i = 0; i < npoint; i++) 
    {

        for (int j = 0; j < npoint; j++)
        {
            if(distance_matrix[i][j]<m)
            {
                m=distance_matrix[i][j];
            }
        }
    }
    printf("\n The value of minimum distance is %.2lf",m);
 double transpose[MAX_POINTS][MAX_POINTS];
    for(int i=0;i<npoint;i++)
    {
        for( int j=0;j<npoint;j++)
        {
           if(transpose[j][i]=distance_matrix[j][i]);
            int c=0;
            c++;
        }
    }
    return 0;
 }
    



    

