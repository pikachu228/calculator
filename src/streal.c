#include <stdlib.h>
#include <assert.h>
#include "streal.h"
#include <stdbool.h>
#include <math.h> 

static double *elements = 0; // Указатель на массив эл-тов
static int max_size = 0;     // Размер массива
static int sp = (-1);        // Индекс вершины стека
    void st_init(int maxSize) { // Начать работу (вх:
    max_size = maxSize;
    elements = (double *) malloc(
    max_size * sizeof(double)
    );
    sp = (-1);
    }

    void st_terminate() { // Закончить работу
        if(elements != 0) {
            free(elements);
        }
    }

    void st_push(double x) { // Добавить эл-т (вх: вещ x)
        assert(elements != 0 && sp < max_size-1);
        ++sp;
        elements[sp] = x;
    }

    double st_pop() { // Взять элемент: вещ
        assert(sp >= 0); // утв: стек не пуст
       --sp;            // элемент удаляется из стека
            return elements[sp + 1];
    }

    double st_top() { // Вершина стека: вещ
        assert(sp >= 0); // утв: стек не пуст
            return elements[sp];
    }

    int st_size() { // Текущий размер стека: цел
            return (sp + 1);
    }

    bool st_empty() { // Стек пуст? : лог
            return (sp < 0);
    }

    int st_maxSize() { // Макс. размер стека: цел
            return max_size;
    }

    bool st_freeSpace() { // Есть своб. место? : лог
            return (sp < max_size - 1);
    }

    void st_clear() { // Удалить все элементы
         sp = (-1);
    }

    double st_elementAt(int i) { // Элемент стека на
                             //   глубине (вх: i): вещ
         assert(elements != 0 && 0 <= i && i < st_size());
            return elements[sp - i];
    }
