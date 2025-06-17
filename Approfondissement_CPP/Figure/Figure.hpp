#define FIGURE
#ifdef FIGURE

class Figure
{
    public :
    Figure();
    virtual ~Figure(); // Destructeur toujours virtuel quand polymorphisme

    virtual void afficher() const;
    virtual double perimetre()const=0;
    virtual double aire()const=0;

};


// classes filles 

class Triangle : public Figure
{
    public :
    Triangle(double h, double b, double c);
    virtual ~Triangle();

    virtual void afficher() const;
    virtual double perimetre()const;
    virtual double aire()const;

    protected :
    double m_hauteur;
    double m_base;
    double m_cote;
};

class Triangle_rect : public Triangle
{
    public :
    Triangle_rect(double h, double b, double c);
    virtual ~Triangle_rect();

    double calculer_hypotenuse()const;
    void afficher()const;

};


class Carre : public Figure
{
    public :
    Carre(double cote);
    virtual ~Carre();

    virtual void afficher() const;
    virtual double perimetre()const;
    virtual double aire()const;

    private :
    double m_cote;
};


class Rectangle : public Figure
{
    public :
    Rectangle(double longueur, double largeur);
    virtual ~Rectangle();

    virtual void afficher() const;
    virtual double perimetre()const;
    virtual double aire()const;

    private :
    double m_longueur;
    double m_largeur;
};


class Cercle : public Figure
{
    public :
    Cercle(double rayon);
    virtual ~Cercle(); 
    virtual void afficher() const;
    virtual double perimetre()const;
    virtual double aire()const;

    private :
    double m_rayon;
};
#endif