# mp3 id3v2 metadata editor

Для того чтобы воспользоваться *редактором*:

1. Скачать файлы с исходным кодом *main.c*
2. Скомпилировать программу с помощью комманды:
```
gcc -o ./editor.exe ./main.c
```
3. Запустить **editor.exe** с данными параметрами:

| Параметр | Описние |
|---|---|
|**--filepath=file**|Выбор файла с именем *file* для редактирования|
|**--show**|Отображение всей метаинформации в виде таблицы|
|**--set=prop_name** **--value=prop_value** |Выставляет значение определенного поля метаинформации с именем *prop_name* в значение *prop_value*|
|**--get=prop_name**|Вывести определенное поле метаинформации с именем *prop_name*|
