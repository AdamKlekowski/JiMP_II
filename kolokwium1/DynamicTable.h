class DynamicTable{
private:
    double *table;
    int length;
    int last;

    void Resize(int newSize);
public:
    DynamicTable();
    DynamicTable(int initLength);
    ~DynamicTable();

    void Add(double element);
    double Get(int index);
    void Set(double element, int index);
    void Print();
};