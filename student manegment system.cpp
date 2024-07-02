#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string first_name;
    std::string last_name;
    std::string student_ID;
    int degree_opted;
    std::string branch_opted;
    int tuition_fees = 0;
    static int id_btech;
    static int id_mtech;
    static std::vector<std::pair<std::string, int>> arr;

public:
    Student() {
        std::cout << "Enter student First Name: ";
        std::cin >> first_name;

        std::cout << "Enter student Last Name: ";
        std::cin >> last_name;

        std::cout << "1 - B.TECH\n2 - M.TECH\nEnter course to enroll for: ";
        std::cin >> degree_opted;

        setStudentID();

        branch_details();
    }

private:
    void setStudentID() {
        if (degree_opted == 1) {
            id_btech++;
            student_ID = "B" + std::to_string(id_btech);
        }
        else if (degree_opted == 2) {
            id_mtech++;
            student_ID = "M" + std::to_string(id_mtech);
        }
    }

    void branch_details() {
        arr.push_back(std::make_pair("Computer Science", 1000));
        arr.push_back(std::make_pair("Information Technology", 800));
        arr.push_back(std::make_pair("Electronics and Telecommunication", 600));
        arr.push_back(std::make_pair("Mechanical", 400));
    }

public:
    void enroll() {
        branch_details();
        for (int i = 0; i <= 3; i++) {
            std::cout << (i + 1) << " - " << arr[i].first << " Rs" << arr[i].second << std::endl;
        }
        std::cout << "Enter Branch to enroll for: ";
        int temp;
        std::cin >> temp;
        this->branch_opted = arr[temp - 1].first;
        this->tuition_fees = arr[temp - 1].second;
    }

    void view_balance() {
        std::cout << "Outstanding Amount = " << tuition_fees << std::endl;
    }

    void run() {
        view_balance();
        while (true) {
            std::cout << "Enter amount to pay: ";
            int amount;
            std::cin >> amount;
            if (amount > tuition_fees) {
                std::cout << "Enter valid amount" << std::endl;
            }
            else {
                tuition_fees -= amount;
                std::cout << "Payment of " << amount << " successful" << std::endl;
                break;
            }
        }
    }

    void showInfo() {
        std::cout << "Name: " << first_name << " " << last_name << "\nStudent_Id: " << student_ID
                  << "\nBranch_opted: " << branch_opted << "\nOutstanding Fees: " << tuition_fees << std::endl;
    }
};

int Student::id_btech = 0;
int Student::id_mtech = 0;
std::vector<std::pair<std::string, int>> Student::arr;

int main() {
    Student student;
    student.enroll();
    student.run();
    student.showInfo();
    return 0;
}