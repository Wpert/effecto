# effecto

Приложение по "Фильтрации" изображения. На данный момент реализованы лишь размытие, повышение резкости, выделение границ и эффект движения.

Алгоритм фильтрации работает за O(image_len * filter_len), но в планах планируется использование быстрого преобразования фурье, пока ещё не знаю буду сам его реализовывать или подключу какую-то библиотеку.

<место для вставки видеоряда>


# Сборка приложения:

1) Требуется установить SFML-2.6.1

2) Прописать в путь до него в CMakeLists.txt

После чего требуется собрать через cmake и, наконец, запустить программу.


# Использование приложения:

1) Загрузите требуемое изображение в директорию "pictures/"

2) Нажмите на кнопку "Load / Save image"

3) Напишите в соответсвующем текстовом окне название файла, нажмите на кнопку "Load image"
