#include <iostream>

std::string returnOnes(char number){
    switch(number){
        case '0':
            return "";
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

std::string returnTens(char number){
    switch(number){
        case '0':
            return "";
        case '1':
            return "one";
        case '2':
            return "twenty";
        case '3':
            return "thirty";
        case '4':
            return "fourty";
        case '5':
            return "fifty";
        case '6':
            return "sixty";
        case '7':
            return "seventy";
        case '8':
            return "eightty";
        case '9':
            return "ninety";
    }
}

std::string tenToTwenty(std::string numbersStr){
    int numbersInt = std::stoi(numbersStr);
    switch(numbersInt){
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 12:
            return "twelve";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 19:
            return "eighteen";
        case 20:
            return "nineteen";
    }
}

std::string returnHundreds(std::string numbers, int scale){
    std::string returnString = "";
    std::string numbersStr = numbers;
    std::string multiplier [4] = {"thousand", "million", "billion", "hundred"};
    int length = numbersStr.length();
    for (int i = length; i > 0; i--){
        if (i == 3){
            returnString.append(returnOnes(numbersStr.front()) + " ");
            returnString.append(multiplier[3] + " ");
            numbersStr = numbersStr.erase(0, 1);
        }
        else if (i == 2)
        {
            if (numbersStr.front() == '1'){
                returnString.append(tenToTwenty(numbersStr) + " ");
                if (scale >= 1){
                    returnString.append(multiplier[scale-1] + " ");
                }
                break;
            }
            returnString.append(returnTens(numbersStr.front()) + " ");
            numbersStr = numbersStr.erase(0, 1);
        }
        else if (i == 1)
        {
            returnString.append(returnOnes(numbersStr.front()) + " ");
            if (scale >= 1){
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