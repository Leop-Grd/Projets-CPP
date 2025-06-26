#include "RepresentationEtat.hpp"

using namespace std;

RepresentationEtat::RepresentationEtat() : m_A(0,0,0.0),m_B(0,0,0.0),m_C(0,0,0.0),m_D(0)
{
}

RepresentationEtat::~RepresentationEtat()
{
}

void RepresentationEtat::print_commande(Fdt const& TF)
{
    // Récupération des coeffs des polynomes entrés en lignes de commande dans le main
    auto coeff_Num = TF.getNum().getCoeff();
    auto coeff_Den = TF.getDen().getCoeff();

    int m = coeff_Num.size(); 
    int n = coeff_Den.size();
    
    if (m>n)
    {
        cout << "Error: Numerator's order superior to Denominator's order, can't continue";
        return;
    }

    // Normalisation si a0 != 1
    double a0 = coeff_Den[0];
    if (a0 != 1.0) {
        for (auto& c :coeff_Num) c /= a0;
        for (auto& c :coeff_Den) c /= a0;
    }
    
    vector<vector<double>> A_coeffs(n, vector<double>(n,0.0)); // on remplit la matrice de 0
    vector<vector<double>> B_coeffs(n,vector<double>(1,0.0));
    vector<vector<double>> C_coeffs(1,vector<double>(n,0.0));

    // Matrice A
    for (int i=0; i<n-1; i++)
    {
        A_coeffs[i][i+1] = 1.0 ; // on place les 1 selon la forme canonique
    }

    for (int i=0; i<n; i++)
    {
        A_coeffs[n-1][i] = -coeff_Den[i]; // on place les coeff du Den selon la forme caninique de commande 
    }
    m_A = Matrice(A_coeffs);

    // Matrice B
    B_coeffs[n-1][0]=1.0;
    m_B = Matrice(B_coeffs);

    // Matrice C
    for (int i=0;i<m;i++)
    {
        C_coeffs[0][i] = coeff_Num[i];
    }
    
    if (n>m)
    {
        for (int i=m; i<n; i++)
            C_coeffs[0][i] = 0.0;
    }

    m_C=Matrice(C_coeffs);
    

    // Affichage
    cout << "\nCommand state-space representation: {x(k+1) = Ax(k) + Bu(k) with: " << endl;
    cout << "                                    {  y(k) = Cx(k)" << endl;
    cout << "A Matrice : " << endl << m_A << endl;
    cout << "B Matrice : " << endl << m_B << endl;
    cout << "C Matrice : " << endl << m_C << endl;
}


void RepresentationEtat::print_observation(Fdt const& TF)
{
    // Récupération des coeffs des polynomes entrés en lignes de commande dans le main
    auto coeff_Num = TF.getNum().getCoeff();
    auto coeff_Den = TF.getDen().getCoeff();

    int m = coeff_Num.size(); 
    int n = coeff_Den.size();
    
    if (m>n)
    {
        cout << "Error: Numerator's order superior to Denominator's order, can't continue";
        return;
    }
    
    vector<vector<double>> A_coeffs(n,vector<double>(n,0.0)); // on remplit la matrice de 0
    vector<vector<double>> B_coeffs(n,vector<double>(1,0.0));
    vector<vector<double>> C_coeffs(1,vector<double>(n,0.0));


    // Normalisation si a0 != 1
    double a0 = coeff_Den[0];
    if (a0 != 1.0) {
        for (auto& c :coeff_Num) c /= a0;
        for (auto& c :coeff_Den) c /= a0;
    }


    // Matrice A
    for (int i=0; i<n-1; i++)
    {
        A_coeffs[i+1][i] = 1.0 ; // on place les 1 selon la forme canonique
    }

    for (int i=0; i<n; i++)
    {
        A_coeffs[0][i] = -coeff_Den[i+1]; // on place les coeff du Den selon la forme caninique de commande 
    }
    m_A = Matrice(A_coeffs);


    // Matrice B
    for (int i=0; i<m; i++)
        B_coeffs[0][i]=coeff_Num[i+1];
    m_B = Matrice(B_coeffs);


    // Matrice C
    C_coeffs[0][0] = 1;
    m_C=Matrice(C_coeffs);
    

    // Matrice D
    m_D = coeff_Num[0];


    // Affichage
    cout << "\nobservation state-space representation: {x(k+1) = Ax(k) + Bu(k) with: " << endl;
    cout << "                                        {  y(k) = Cx(k) + Du(k)" << endl;
    cout << "A Matrice : " << endl << m_A << endl;
    cout << "B Matrice : " << endl << m_B << endl;
    cout << "C Matrice : " << endl << m_C << endl;
    cout << "D Matrice : " << m_D << "\n" << endl;
}
