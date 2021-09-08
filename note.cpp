//// Print Bit
#include <bitset>
...

char a = -58;
std::bitset<8> x(a);
std::cout << x << '\n';

short c = -315;
std::bitset<16> y(c);
std::cout << y << '\n';

//// Class 밖에서 private 변수 접근. (주로 operator overloading 할때)
class Student {
...

    friend ostream& operator<<(ostream& os, Student& stu);
}

ostream& operator<<(ostream& os, Student& stu){
    // impl here...
}


//// 순열 (ex. 5P3) : 중복 검사 필요!
vector<int> test_list = {0, 1, 2, 3, 4};
do {
    for (int i = 0 ; i < 3 ; i++)
        cout << test_list[i] << ", ";
    cout << endl;
} while(next_permutation(test_list.begin(), test_list.end()));

//// 조합 (ex. 5C3) : 중복 없음.
vector<int> test_list = {0, 1, 2, 3, 4};
vector<bool> mask = {0,0,1,1,1};
do {
    for (int i = 0 ; i < 5 ; i++){
        if (mask[i])
            cout << test_list[i] << ", ";
    }
    cout << endl;
} while(next_permutation(mask.begin(), mask.end()));

//// remove 와 remove_if
{
  std::string str1 = "Text with some   spaces";
  // 문자열에서 띄어쓰기를 모두 지운다.
  str1.erase(std::remove(str1.begin(), str1.end(), ' '), str1.end());
  std::cout << str1 << '\n';

  std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
  // 문자열에서 공백 문자 (띄어쓰기, 개행 문자 등등)를 지운다.
  str2.erase(std::remove_if(str2.begin(), str2.end(),
                            [](unsigned char x) { return std::isspace(x); }),
             str2.end());
  std::cout << str2 << '\n';
}

