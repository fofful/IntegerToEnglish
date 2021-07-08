#include <iostream>

std::string returnHundreds(std::string numbers){
    std::cout << numbers << "dsadad "<<  std::endl;
    return "asd";
}

int main(){
    std::cout << "give an integer number: " << std::endl;
    int num = 0;
    std::string numAsStr;
    std::string answer;
    
    answer.empty();
    numAsStr.empty();

    std::cin >> num;
    numAsStr = std::to_string(num);
    int scale = (numAsStr.length() - (numAsStr.length() % 3)) / 3;
    std::cout << "scale is: " << scale << std::endl;
    for (int i = scale; i > 0; i--){
        std::cout << "numAsStr is: " << numAsStr << std::endl;
        std::string numbers = numAsStr.substr(0, numAsStr.length()-((i-1)*3));
        numbers = returnHundreds(numbers);
        answer.append(numbers);
        numAsStr.erase(0,3);
    };
    std::cout << "number given in english is: " << answer << std::endl;
    return 0;
}

