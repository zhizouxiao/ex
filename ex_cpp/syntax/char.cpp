/* hello world by wzp.
 */
#include<iostream>

int main()
{
    char ch(97);
    std::cout << sizeof(ch) << ch << std::endl;
    std::cout << static_cast<int>(ch) << std::endl;
    return 0;
}
