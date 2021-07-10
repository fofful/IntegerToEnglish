#include <iostream>

std::string returnTens(char number){
    switch(number){
        case '0':
            return "zero";
        case '1':
            return "one";
        case '2':
            return "two";
        case '3':
            return "three";
        case '4':
            return "four";
        case '5':
            return "five";
        case '6':
            return "six";
        case '7':
            return "seven";
        case '8':
            return "eight";
        case '9':
            return "nine";
    }
}

std::string returnHundreds(std::string numbers, int scale){
    std::string returnString = "";
    std::string numbersStr = numbers;
    std::string multiplier [5] = {"thousand", "million", "billion", "hundred", "ten"};
    int length = numbersStr.length();
    for (int i = length; i > 0; i--){
        if (i == 3){
            returnString.append(returnTens(numbersStr.front()) + " ");
            returnString.append(multiplier[3] + " ");
            numbersStr = numbersStr.erase(0, 1);
        }
        else if (i == 2)
        {
            returnString.append(returnTens(numbersStr.front()) + " ");
            returnString.append(multiplier[4] + " ");
            numbersStr = numbersStr.erase(0, 1);
        }
        else if (i == 1)
        {
            returnString.append(returnTens(numbersStr.front()) + " ");
            if (scale > 1){
                returnString.append(multiplier[scale-1] + " ");
            }
            numbersStr = numbersStr.erase(0, 1);
        }
    }
    return returnString;
}

int main(){
    
    int num = 0;
    std::string numAsStr = "";
    std::string answer = "";
    std::string numbers = "";

    std::cout << "give an integer number: " << std::endl;
    std::cin >> num;
    numAsStr = std::to_string(num);
    int scale = (numAsStr.length() - (numAsStr.length() % 3)) / 3;

    for (int i = scale; i >= 0; i--){
        numbers.empty();
        numbers = numAsStr.substr(0, numAsStr.length()-(i*3));
        numbers = returnHundreds(numbers, i);
        answer.append(numbers);
        numAsStr.erase(0, numAsStr.length()-(i*3));
    };

    std::cout << "number given in english is: " << answer << std::endl;
    return 0;
}