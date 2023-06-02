#include<iostream>
#include<string>
/*
	B2.1
	Thiet ke class the hien mot doi tuong Hoc sinh trong thuc te 
	+ Các thuoc tinh và data type tuong ung
		- ma hoc sinh - int
		- ten - string
		- tuoi - int
		- que quan - string
		- chieu cao - float
		- can nang - float
		- diem trung binh 8 môn hoc Toan, Ly, Hoa, Van, Anh, Sinh, Su, Ðia - mang/vector
		- Phuong thuc
		- gioi thieu ban than gom ten, tuoi, que quan
		- show bang diem cua 8 môn hoc
		- show hoc luc, neu trung binh 8 mon tren 8 là gioi, tu 5 den 8 la kha va con lai la trung binh
		- Tu tao ham main va test cac phuong thuc. Luu y: cac doi tuong can cap phat dong
*/
class HocSinh {

private:
	int ma;
	std::string ten;
	int tuoi;
	std::string que_quan;
	float chieu_cao;
	float can_nang;
	float diemTB[8];


public:
	void gioi_thieu(std::string ten, int tuoi, std::string que_quan, float diem[]) {
		std:: cout << "Toi ten la " + ten + "\n";
		std:: cout << "Nam nay toi " << tuoi << " tuoi\n";
		std:: cout << "Toi sinh ra tai " + que_quan + "\n";
	}

	void show_bang_diem(int ma, std::string ten, float diem[]) {
		std:: cout << "Diem trung binh cua hoc sinh nhu sau\n";
		std::cout << "Ten: " + ten + "\n";
		std::cout << "Ma HS: " << ma << "\n";

		std::cout << "Toan = " << diem[0] << "\n";
		std::cout << "Ly = " << diem[1] << "\n";
		std::cout << "Hoa = " << diem[2] << "\n";
		std::cout << "Van = " << diem[3] << "\n";
		std::cout << "Anh = " << diem[4] << "\n";
		std::cout << "Sinh = " << diem[5] << "\n";
		std::cout << "Su = " << diem[6] << "\n";
		std::cout << "Dia = " << diem[7] << "\n";
	}

	void show_hoc_luc(int ma, std::string ten, float diem[]) {
		std::cout << "Show hoc luc\n";
		std::cout << "Ma HS: " << ma << "\n";
		std::cout << "Ten: " << ten << "\n";

		float tong = 0.0;
		for (int i = 0; i < 8; i++) {
			tong += diem[i];
		}

		float diemTB = tong/ 8.0;

		if (diemTB > 8) {
			std::cout << "Hoc luc: Gioi\n";
		}
		else if (diemTB >= 5 && diemTB <= 8) {
			std::cout << "Hoc luc: Kha\n";
		}
		else {
			std::cout << "Hoc luc: TB\n";
		}
	}

};

int main() {
	HocSinh *myHS = new HocSinh;
	float diemTB[] = { 8.1, 8.2, 8.3, 8.4, 8.5, 8.6, 8.7, 8.8 };
	// Yeu cau 1: myHS->gioi_thieu("Le Cong Vi", 21, "Quang Nam", diemTB);
	// Yeu cau 2: myHS->show_bang_diem(20101951, "Le Cong Vi", diemTB);
	// Yeu cau 3: myHS->show_hoc_luc(20101951, "Le Cong Vi", diemTB);
}
