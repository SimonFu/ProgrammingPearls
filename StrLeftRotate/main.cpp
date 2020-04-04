#include <QCoreApplication>
#include <QDebug>
#include <vector>

char* string_left_rotate(char* s, int n, int shift)
{
    std::vector<bool> moved(shift, false);

    for(int i = 0; i < shift; ++i)
    {
        if(moved[i]) continue;

        char t = s[i];
        int j = 0;
        while((i + (j + 1) * shift) % n != i)
        {
            s[(i + j * shift) % n] = s[(i + (j + 1) * shift) % n];
            if((i + (j + 1) * shift) % n < shift && !(moved[(i + (j + 1) * shift) % n]))
                moved[(i + (j + 1) * shift) % n] = true;

            ++j;
        }
        s[(i + j * shift) % n] = t;
        moved[i] = true;
    }

    return s;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char s[] = "abcdefghjklm";

    qDebug() << string_left_rotate(s, sizeof(s) - 1, 3);

    return a.exec();
}
