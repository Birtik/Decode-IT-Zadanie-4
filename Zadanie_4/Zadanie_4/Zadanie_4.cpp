#include <iostream>

using namespace std;

class Task
{
    unsigned int n;
    string password;
    int* convertedPassword;
    int* codes;

public:

    void SetValues()
    {
        try
        {
            cin >> n;

            if (n < 1 || n > 11) throw 1;

            cin >> password;

            if (password.length() != 4 * n) throw 1;

            convertedPassword = new int[4 * n];

            for (int i = 0; i < 4 * n; i++)
            {
                convertedPassword[i] = (int)password[i] - 48;
            }
        }
        catch (int x) {
            cout << "Incorrect input data!";
            exit(0);
        }

        codes = new int[n];
    }

    void FindCode()
    {
        for (int i = 0, j = 0; i < n; j += 4, i++)
            codes[i] = ((convertedPassword[j] * 10 + convertedPassword[j + 2] * 1) + ((convertedPassword[j + 1] * 10 + convertedPassword[j + 3] * 1)));
    }

    void GetCodes()
    {
        for (int i = 0; i < n; i++)
            cout << (char)codes[i];

        cout << endl;
    }
};


int main()
{
    unsigned int t;
    cin >> t;

    Task** task = new Task * [t];

    for (int i = 0; i < t; i++)
    {
        task[i] = new Task;
        task[i]->SetValues();
        task[i]->FindCode();
    }

    for (int i = 0; i < t; i++)
    {
        task[i]->GetCodes();
        delete task[i];
    }

    delete[] task;
}

