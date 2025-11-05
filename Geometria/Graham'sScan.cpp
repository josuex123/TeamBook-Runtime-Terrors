struct Point{
    int x, y;
    bool operator<(const Point &other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    bool operator==(const Point &other)const{
        return x == other.x && y == other.y;
    }
};


void printPoints(const vector<Point>& points) {
    for (const auto& point : points) {
        cout << "(" << point.x << ", " << point.y << ")" << endl;
    }
}

/*
    Function that returns 
    1 if the points are clockwise,
    -1 if the points are anticlockwise,
    0 if they are colineal
*/
int areClockwise(Point p1, Point p2, Point p3){
     int ax = p1.x, ay = p1.y;
     int bx = p2.x, by = p2.y;
     int cx = p3.x, cy = p3.y;

     int result = by*(cx - ax) + ay*(bx - cx) + cy*(ax-bx);
    //  cout << "result" << result << endl;
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}


vector<Point> grahamsScan(vector<Point> points){
    sort(points.begin(), points.end());
    int n = points.size();

    vector<Point> up,down;

    Point firstPoint = points[0], lastPoint = points[n-1];

    down.push_back(firstPoint);
    up.push_back(firstPoint);

    for (int i = 1; i < n; i++)
    {
        Point currentPoint = points[i];
        int clockwise = areClockwise(firstPoint,currentPoint,lastPoint);
        if( i == n-1 || clockwise > 0 ){
            while(up.size() >= 2 && areClockwise(up[up.size() - 2], up[up.size()-1], currentPoint) < 1 ){
                up.pop_back();
            }
            up.push_back(currentPoint);
        }
        
        if(i == n-1 || clockwise < 0){
            while(down.size() >= 2 && areClockwise(down[down.size() - 2], down[down.size()-1], currentPoint) > -1 ){
                down.pop_back();
            }
            down.push_back(currentPoint);
        }
    }


    
    points.clear();
    for (int i = 0; i < up.size(); i++)
    {
        points.push_back(up[i]);
    }
    for (int i = 0; i < down.size(); i++)
    {
        points.push_back(down[i]);
    }

    sort(points.begin(), points.end());

    points.resize(unique(points.begin(),points.end()) - points.begin());

    return points;

}
