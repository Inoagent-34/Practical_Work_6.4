#include <stdio.h>
#include <stdint.h>


void Counter(void);              //Прототип функции счёта по убыванию
void Multiplication_Table(void); //Прототип функции, создающей таблицу умножения
void Sorting(void);              //Прототип функции, сортирующей введенные числа по возрастанию

int main() //Главная функция
{
   uint8_t select; //Переменная, вводимая с консоли, значение которой определяет дальнейшую работу программы (в диапазоне 0...255)

   printf("List of available button numbers \n ");    //Вывод строки "Список доступных номеров кнопок"
   printf("Button 1: Show counter 9...0 \n ");        //Вывод строки "Кнопка 1: Показать счетчик 9...0"
   printf("Button 2: Show multiplication table \n");  //Вывод строки "Кнопка 2: Показать таблицу умножения"
   printf("Button 3: Sorting of inputed values \n");  //Вывод строки "Кнопка 3: Сортировка введенных чисел

   while(1) //Бесконечный цикл, в котором выполняется программа
   {
     printf("\n");        //Переход на новую строку
     printf("Push number button 1, 2 or 3 and push Enter button "); //Вывод строки "Нажмите кнопу 1, 2 или 3 и нажмите Enter"
     scanf("%d",&select); //Ввод команды с консоли
     printf("\n");        //Переход на новую строку

     switch(select) //Выбор дальнейшего пути выполнения программы в зависимости от значения select
    {
     case 1:                      //Если 1, вызвать функцию счёта по убыванию
         Counter();
     break;
     case 2:                      //Если 2, вызвать функцию создания таблицы умножения
         Multiplication_Table();
     break;
     case 3:                      //Если 3, вызвать функцию, сортирующей введенные числа по возрастанию
         Sorting();
     break;
     default:                     //Если нет совпадения ни с 1, ни с 2, ни с 3, вывод указания о необходимости ввода корректного числа
         printf("The number incorrect. Please enter correct number. \n");
    }
   }
    return 0;
}

//Функция счета по убыванию
void Counter(void)
{
    int i=9;             //Переменная цикла (в диапазоне -127...+127), начальное значение - 9
    while(i>=0)         //Счет от 9 до 0 по убыванию
    {
      printf("%d \n", i); //Вывод значения переменной на каждой итерации
      i--;
    }
    printf("\n");         //Переход на новую строку
}

//Вывод таблицы умножения
void Multiplication_Table(void)
{
    uint8_t i, j;     //Переменные циклов (в диапазоне 0...255)
    uint8_t mul;      //Результат умножения
    printf("Multiplication table: \n"); //Вывод строки "Таблица умножения:"
    for(i=1;i<10;i++)       //Перебор строк таблицы
    {
        for(j=1;j<10;j++)   //Перебор элементов каждой строки
        {
          mul=i*j;          //Вычисление произведения
          printf("%d",mul); //Вывод произведения
          //Манипуляции для выравнивания размеров полученной таблицы
          if((i==1)&&(j==9))  //После прохода последнего элемента 1-ой строки...
          {
           printf("\n");      //...ввести горизонтальный промежуток
          }
          //Чтобы числа в таблице были расположены ровно друг над другом
          (mul<10)? printf("  "): printf(" "); //Если результат не больше 10, вводить двойной пробел, если больше-одинарный
        }
        printf("\n"); //Переход на следующую строку
    }
}

//Сортировка пяти введённых чисел по возрастанию (в диапазоне -32768...+32768)
void Sorting(void)
{
   int16_t Array_1[5]; //Массив хранения введённых данных
   int16_t Array_2[5]; //Массив хранения отсортированных данных
   int8_t i, j;       //Переменные циклов
   int16_t max_value;  //Максимальное значение при сортировке
   int8_t max_index;   //Номер элемента массива, соответствующий максимальному значению при сортировке

   printf("Input five integer values \n "); //Вывод заголовка "Введите пять целых чисел

   //Цикл для ввода значений в массив Array_1
   for(i=0;i<5;i++)
   {
     scanf("%d",&Array_1[i]);  //Ввод данных
   }
   printf("\n");     //Переход на следующую строку

   //Вывод введенных данных в строку
   printf("Entered numbers:\n");
   for(i=0;i<5;i++)
   {
      printf("%d, ", Array_1[i]);
   }
   printf("\n"); //Переход на следующую строку
   //Цикл сортировки, массив Array_2, на убывание
   for(j=4;j>=0;j--)
   {
     max_value=-32768;     //В максимальное значение в начале каждой интерации для массива Array_2 записывется наименьшее возможное значение
     for(i=0;i<5;i++)      //Цикл, проходящий элементы массива Array_1 по возастанию
     {
         if(max_value<Array_1[i])  //Если текущее максимальное значение меньше очередного элемента массива Array_1...
         {
             max_value=Array_1[i]; //...максимальному значению присваивается значение этого элемента
             max_index=i;          //При этом запоминается значение индекса элемента массива Array_1, соответствующее текущему максимуму
         }
     }
     //После заверщения опроса всех элементов массива Array_1 на позицию бывшего максимального значения в Array_1 записывется наименьшее возможное значение
     Array_1[max_index]=-32768;
     Array_2[j]=max_value;  //В позицию элемента массива Array_2 записывается найденное максимальное значение
   }
   printf("Sorted numbers:\n"); //Вывод заголовка "Отсортированные числа"
   for(i=0;i<5;i++)             //Цикл для вывода отсортированных чисел из массива Array_2, по возрастанию
   {
       printf("%d, ", Array_2[i]); //Вывод каждого элемента массива
   }
}
