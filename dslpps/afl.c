#include<stdio.h>
#include<math.h>
#define MAX_POINTS 10

typedef struct {
    double x;
    double y;
} Point;

double calculate_distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));//formulae to calculate the eucledeon
}

int main() {
    int num_points;
    printf("Enter the number of points up to %d ", MAX_POINTS);
    scanf("%d", &num_points);

    if (num_points <= 0 || num_points > MAX_POINTS) {
        printf("Invalid number of points.\n");
        return 1;
    }

    Point points[MAX_POINTS];//entering the points in a matrix points
    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < num_points; i++) {
        printf("Point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
        double distance_matrix[MAX_POINTS][MAX_POINTS];
    printf("\nDistance Matrix:\n");
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < num_points; j++) {
            distance_matrix[i][j] = calculate_distance(points[i], points[j]);
            printf("%.2lf\t", distance_matrix[i][j]);
        }
        printf("\n");
    }
    double m=distance_matrix[0][0];
    printf("the minimum distance coordiantes are");//smallest distance
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < num_points; j++)
        {
            if(distance_matrix[i][j]<m)
            {
                m=distance_matrix[i][j];
            }
        }
    }
    printf("the smallest distance is %.2lf",m);
return 0;
}
