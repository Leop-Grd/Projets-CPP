#include <iostream>

using namespace std;

void Dump(int buffer[10], int nb_elements){
    for (int i=0; i<nb_elements; i++){
        cout << buffer[i] << endl;
    }
}


int main(){
    cout << "---buff---\n";
    int buff[]={12,25,8,6,586};
    Dump(buff,5); 

    cout << endl << "---buff2---\n";
    int *buff2 = new int[2];
    buff2[0]=45;
    buff2[1]=100;
    Dump(buff2,2);
    delete buff2;

    return 0;
}
