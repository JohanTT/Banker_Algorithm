
#include <bits/stdc++.h>
using namespace std;

// Ma trận giữ giá trị cho các bảng
int Allocation[10][3], Need[10][3], Max[10][3], Available[10][3];
// p Số lượng Process 
// Work lưu giá trị ban đầu đề cho đồng thời giữ lại giá trị hiện tại
int p, Work[3], IniWork[3];
// Executed để check kiểm tra Process nào đã thực thi 
// Come để kiểm tra Process có xảy ra deadlock hay không
bool Executed[10], Come;

void ResetRow() {
    // Gán lại các giá trị mặc định ban đầu cho các biến
    // Để có thể chạy lại hàm tính
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
             // Tăng biến điếm mỗi khi process đã thực thi
             // j < p - 1 để đừng lại khi j lớn hơn p
				j++;
			}
            // Tìm kiếm process thích ứng để Work có thể cấp cho
            // Kiểm tra Work => Need để tiến hành cấp cho tiến trình
			if (Need[j][0] <= Work[0] && 
			    Need[j][1] <= Work[1] &&
			    Need[j][2] <= Work[2]) {
                // Kiểm tra Tiến trình đã thực thi hay chưa   
				if (!Executed[j]) {
					Executed[j] = true;
					Work[0] += Allocation[j][0];
					Work[1] += Allocation[j][1];
					Work[2] += Allocation[j][2];
					// Đánh dấu come = true để tiếp tục thực hiện
                    // Nếu come không được đánh dấu thì trường hợp deadlock sẽ xảy ra 	
					Come = true;
					cout << "\nProcess P" << j+1;
					cout << "\nWork: " << Work[0] << " " << Work[1] << " " << Work[2] << "\n";
					break;
				}
			}
		}
        // Nếu chạy xong 1 vòng i mà vẫn không có process nào được thực thi => Deadlock 		
		if (!Come) {	
            system("color 4");
			cout << "\n\t\t\tDead lock\n\n";
			break;
		} else {
            // Reset lại biến Come thành false để kiểm tra process tiếp theo có bị Deadlock hay không  
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
                // Reset lại work về giá trị ban đầu
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
                // Reset lại work về giá trị ban đầu
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
                // Reset lại work về giá trị ban đầu
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
                // Reset lại work về giá trị ban đầu
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
