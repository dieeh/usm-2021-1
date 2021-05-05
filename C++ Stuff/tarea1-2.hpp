class A {
private:
    unsigned long tamaño;
    
public:
    A();

    A(unsigned long n);

    A(unsigned long n);

    ~A();

    bool setValue(unsigned long i, int v);

    int getValue(unsigned long i);

    void append(int v);

    void remove();

    unsigned long size();
};


