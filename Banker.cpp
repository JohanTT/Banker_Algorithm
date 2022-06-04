#include <bits/stdc++.h>
using namespace std;

// Ma tr?n gi? gi� tr? cho c�c b?ng
int Allocation[10][3], Need[10][3], Max[10][3], Available[10][3];
// p S? lu?ng Process 
// Work luu gi� tr? ban d?u d? cho d?ng th?i gi? l?i gi� tr? hi?n t?i
int p, Work[3], IniWork[3];
// Executed d? check ki?m tra Process n�o d� th?c thi 
// Come d? ki?m tra Process c� x?y ra deadlock hay kh�ng
bool Executed[10], Come;

void ResetRow() {
    // G�n l?i c�c gi� tr? m?c d?nh ban d?u cho c�c bi?n
    // �? c� th? ch?y l?i h�m t�nh
	Come = false;
	for (int i = 0; i < 10; ++i)    {
		Executed[i] = false;
	}
}

void Banker() {
    system("cls");
	ResetRow();
    cout << "\n\n\tTable for Bankers Algo\n\n";
	cout << "Process    Max    Allocation    Need" << endl;
	for (int i = 0; i < p; ++i)	{
		cout << "  P" << i + 1 << "    ";
		cout << "  " << Max[i][0] << " " << Max[i][1] << " " << Max[i][2] << "     ";
		cout << " " << Allocation[i][0] << " " << Allocation[i][1] << " " << Allocation[i][2] << "     ";
		cout << " " << Need[i][0] << " " << Need[i][1] << " " << Need[i][2];
		cout << endl;
	}
	cout << "Initial Available: " << Work[0] << " " << Work[1] << " " << Work[2] << "\n\n";
	
	for (int i = 0; i < p; ++i)	{
		for (int j = 0; j < p; ++j) {
			while (Executed[j] && j < p - 1) {
             // Tang bi?n di?m m?i khi process d� th?c thi
             // j < p - 1 d? d?ng l?i khi j l?n hon p
				j++;
			}
            // T�m ki?m process th�ch ?ng d? Work c� th? c?p cho
            // Ki?m tra Work => Need d? ti?n h�nh c?p cho ti?n tr�nh
			if (Need[j][0] <= Work[0] && 
			    Need[j][1] <= Work[1] &&
			    Need[j][2] <= Work[2]) {
                // Ki?m tra Ti?n tr�nh d� th?c thi hay chua   
				if (!Executed[j]) {
					Executed[j] = true;
					Work[0] += Allocation[j][0];
					Work[1] += Allocation[j][1];
					Work[2] += Allocation[j][2];
					// ��nh d?u come = true d? ti?p t?c th?c hi?n
                    // N?u come kh�ng du?c d�nh d?u th� tru?ng h?p deadlock s? x?y ra 	
					Come = true;
					cout << "\nProcess P" << j+1;
					cout << "\nWork: " << Work[0] << " " << Work[1] << " " << Work[2] << "\n";
					break;
				}
			}
		}
        // N?u ch?y xong 1 v�ng i m� v?n kh�ng c� process n�o du?c th?c thi => Deadlock 		
		if (!Come) {	
            system("color 4");
			cout << "\n\t\t\tDead lock\n\n";
			break;
		} else {
            // Reset l?i bi?n Come th�nh false d? ki?m tra process ti?p theo c� b? Deadlock hay kh�ng  
			Come = false;
		}
		if (i == p - 1) {
            cout << "\nProcess executed without Deadlock";
		}
	}
	bool Continue = true;
	while (Continue) {
		int val, pro;
		cout << "\n\nSelect Below oprations:\n\n";
		cout << "1.Add Request for process: " << endl;
		cout << "2.Change Max of process: " << endl;
		cout << "3.Change Allocation of process: " << endl;
		cout << "4.Change Initial Available: " << endl;
		cout << "5.Exit\n\n";
		cin >> val;
		switch(val) {
		    case 1: {
                cout << "\nProcess Number P: ";
                cin >> pro;
                cout << "Request for Allocation: ";
                int R1, R2, R3;
                cin >> R1 >> R2 >> R3;
                Allocation[pro-1][0] += R1;
                Allocation[pro-1][1] += R2;
                Allocation[pro-1][2] += R3;
                IniWork[0] -= R1;
                IniWork[1] -= R2;
                IniWork[2] -= R3;
                // Reset l?i work v? gi� tr? ban d?u
                Work[0] = IniWork[0];
                Work[1] = IniWork[1];
                Work[2] = IniWork[2];
                Banker();
                Continue = false;
                break;
            }
            case 2: {
                cout << "\nProcess Number P: ";
                cin >> pro;
                cout << "New Max: ";
                cin >> Max[pro-1][0] 
                    >> Max[pro-1][1] 
                    >> Max[pro-1][2];
                // Reset l?i work v? gi� tr? ban d?u
                Work[0] = IniWork[0];
                Work[1] = IniWork[1];
                Work[2] = IniWork[2];
                Banker();
                Continue = false;
                break;
            }
            case 3: {
                cout << "\nProcess Number P: ";
                cin >> pro;
                cout << "New Allocation: ";
                cin >> Allocation[pro-1][0] 
                    >> Allocation[pro-1][1] 
                    >> Allocation[pro-1][2];
                // Reset l?i work v? gi� tr? ban d?u
                Work[0] = IniWork[0];
                Work[1] = IniWork[1];
                Work[2] = IniWork[2];
                Banker();
                Continue = false;
                break;
            }
            case 4: {
                cout << "\nNew Initial Available: ";
                cin >> IniWork[0] >> IniWork[1] >> IniWork[2];
                // Reset l?i work v? gi� tr? ban d?u
                Work[0] = IniWork[0];
                Work[1] = IniWork[1];
                Work[2] = IniWork[2];
                Banker();
                Continue = false;
                break;
            }
            case 5: {
                cout << "\t\t\tThanh Vien Nhom: " << endl;
                cout << "\t\t1. Nguyen Thi Thuy Linh - 46.01.104.093" << endl;
                cout << "\t\t2. Pham Vuong Nghia - 46.01.104.118" << endl;
                cout << "\t\t3. Cao Viet Thang - 46.01.104.165" << endl;
                cout << "\t\t4. Nguyen Ngoc Tram - 46.01.104.188" << endl;
                cout << "\t\t5. Le Anh Tri - 46.01.104.195" << endl;
                Continue = false;
                break;
            }
            default: {
                cout << "\t\t\tThanh Vien Nhom: " << endl;
                cout << "\t\t1. Nguyen Thi Thuy Linh - 46.01.104.093" << endl;
                cout << "\t\t2. Pham Vuong Nghia - 46.01.104.118" << endl;
                cout << "\t\t3. Cao Viet Thang - 46.01.104.165" << endl;
                cout << "\t\t4. Nguyen Ngoc Tram - 46.01.104.188" << endl;
                cout << "\t\t5. Le Anh Tri - 46.01.104.195" << endl;
                Continue = false;
                break;
            }
		}
	}
}

int main (){
    system("color 3");
	cout << "Number of Process P: ";
	cin >> p;
	for (int i = 0; i < p; ++i)	{
		cout << "\n\n\t\t\t";
		cout << "Process P" << i + 1 << ":" << endl;
		
		cout << "ALLOCATION:" << endl;
		cout << "A B C" << endl;
		cin >> Allocation[i][0] >> Allocation[i][1] >> Allocation[i][2];
		
		cout << endl << "MAX:" << endl;
		cout << "A B C" << endl;
		cin >> Max[i][0] >> Max[i][1] >> Max[i][2];
		
		Need[i][0] = Max[i][0] - Allocation[i][0];
		Need[i][1] = Max[i][1] - Allocation[i][1];
		Need[i][2] = Max[i][2] - Allocation[i][2];
	}
    cout << endl << "Available: " << endl;
    cout << "A B C" << endl;
	cin >> IniWork[0] >> IniWork[1] >> IniWork[2];
	Work[0] = IniWork[0];
	Work[1] = IniWork[1];
	Work[2] = IniWork[2];
	
	Banker();
	return 0;
}
