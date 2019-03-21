class Point {
private:
    double x, y;

public:
    Point();
    Point(double x, double y);
    ~Point();
    
    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;
    
    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);
};