#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int main(){
  std::string file;
  std::cout << "Enter filename to read: ";
  std::cin >> file;
  std::ifstream infile;
  infile.open(file);
  if (!infile){
    std::cout << "This list does not exist!\n";
    return 1;
  }

  std::vector<int> list1;
  std::vector<int> list2;
  int temp {};
  infile >> temp;
  while(infile){
    list1.push_back(temp);
    infile >> temp;
    list2.push_back(temp);
    infile >> temp;
  }
  infile.close();

  std::sort(list1.begin(), list1.end());
  std::sort(list2.begin(), list2.end());

  int tot {0};
  for (int i{0}; i < list1.size(); i++) {
    std::cout << '\n' << list1.at(i) << '\t' << list2.at(i);
    if(list2.at(i) > list1.at(i)){
      tot += list2.at(i) - list1.at(i);
    }
    else{
      tot += list1.at(i) - list2.at(i);
    }
  }

  std::cout << '\n' << "\nThe distance between the two lists comes out to a total of " 
            << tot << '.' << '\n';

  return 0;
}
