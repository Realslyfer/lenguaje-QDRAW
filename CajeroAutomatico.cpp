/*
==============================================
cajero automatico con cambio de billetes
compilar y correr
==============================================
*/

#include<iostream>
#include<windows.h>
#include<stdlib.h>

#define quinientos  500
#define cien        100
#define cincuenta   50
#define veinte      20
#define diez        10

using namespace std;

//variables globales

float saldo_final = 0.0;
char opc2;
int opc,deposita,retira,QUINIENTOS,CIEN,CINCUENTA,VEINTE,DIEZ;

void Cajero(){
  cout<<"\tDepositar: 1"<<endl;
  cout<<"\tRetirar: 2"<<endl;
  cout<<"\tConsultar: 3"<<endl;
  cout<<"\tSalir: 4"<<endl;
  cout<<"\tOpcion: "; 
  cin>>opc;
}
void Verificar(int &QUINIENTOS, int &CIEN, int &CINCUENTA, int &VEINTE, int &DIEZ){
  switch(opc){
    case 1: 
      cout<<"\n.: Depositar :."<<endl;
      cout<<"Digite el monto a depositar: "; 
      cin>>deposita;
      cout<<"\nDeposito: "<<deposita;
      saldo_final = deposita; 
    break;
    
    case 2:
      cout<<"\n.: Retira :."<<endl;
      //label del goto
      extrae:
      cout<<"\nDigite el monto a retirar: ";
      cin>>retira;
        if(retira>saldo_final){
          cout<<"\nLa extraccion es mayor al saldo, presione una tecla.";
          cin.get();
          goto extrae;
        } 
          else{
            saldo_final -= retira;
            QUINIENTOS = retira/quinientos; retira %= quinientos;
            CIEN = retira/cien; retira %= cien;
            CINCUENTA = retira/cincuenta; retira %= cincuenta;
            VEINTE = retira/veinte; retira %= veinte;
            DIEZ = retira/diez; retira %= diez;
            
            cout<<"\nBilletes entregados como cambio: "<<endl;
            cout<<" 500: "<<QUINIENTOS<<endl;
            cout<<" 100: "<<CIEN<<endl;
            cout<<"  50: "<<CINCUENTA<<endl;
            cout<<"  20: "<<VEINTE<<endl;
            cout<<"  10: "<<DIEZ<<endl;
          }
      break;
      
      case 3: 
        cout<<"\n .: Consultar Saldo :."<<endl;
        cout<<"Saldo actual: "<<saldo_final;
      break;
      
      case 4:
        exit(1);
        break;
          
  }
}
//main =======================================================
int main(){
  cout<<"\n Cajero Virtual"<<endl<<endl;
  rutina:
  Cajero();
  Verificar(QUINIENTOS,CIEN,CINCUENTA,VEINTE,DIEZ);
  
  cout<<"\nDesea continuar operando? (s|n): ";
  cin>>opc2;
  if(opc2 == 's' || opc2 == 'S'){
    system("cls");
    goto rutina;
  }
    else{
      exit(1);
    }
    cin.get();
    return 0;
}
