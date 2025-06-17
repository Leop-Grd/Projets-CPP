class Pen{

    public:
    Pen();
    Pen(int x, int y);
    ~Pen();

    void move(int x, int y);
    void down();
    void up();
    int getX() const;
    int getY() const;
    bool getState() const;

    private:
    int m_x, m_y;
    bool m_state;

};