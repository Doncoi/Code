#include <iostream>
#include <string>
#include <cstdlib>

std::string number;

std::string turning(std::string number)
{
    std::string turned;
    
    bool allzero = true;
    for (int i = 0; i < number.size(); i++)
    {
        if(number[i] != '0')
            allzero = false;
    }
    if (allzero)
        return "0";
    
    for (int i = 0; i < number.size(); i++)
    {
      if(number[i] != '0') break;
      number[i] = '\0';
    }
    
    for (int i = number.size() - 1; i >= 0; i--)
    {
        if (number[i] != '0') break;
        number[i] ='\0';
    }
    
    for (int i = number.size() - 1; i >= 0; i--)
    {
        if (number[i] == '\0') continue;
        turned += number[i];
    }
    return turned;
}

int main() {
    std::cin >> number;
    if(number.find('.') != std::string::npos)
    {
        std::string a, b;
        
        a = turning (number.substr(0,number.find('.')));
        b = turning (number.substr(number.find('.') + 1));
        std::cout << a << '.' << b;
        
        exit(0);
    }
    else if (number.find('/') != std::string::npos)
    {
        std::string a, b;
        a = turning (number.substr(0, number.find('/')));
        b = turning (number.substr(number.find('/') + 1));
        std::cout << a << '/' << b;
        exit(0);
    }
    else if (number.find('%') != std::string::npos)
    {
        std::string a;
        a = turning (number.substr(0, number.size() - 1));
        std::cout << a << '%';
        exit(0);
    }
    else
    {
        std::string a;
        a = turning(number);
        std::cout << a;
    }
    return 0;
}
