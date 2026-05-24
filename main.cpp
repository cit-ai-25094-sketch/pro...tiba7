#include <iostream>
#include <string>

using namespace std;

//   تحديد عدد الأسئلة الثابت في الاختبار
const int TOTAL_QUESTIONS = 3;

// --- تعريف هياكل البيانات (Structures) ---

struct Question {
    string questionText;
    string optionA;
    string optionB;
    string optionC;
    char correctAnswer; // الإجابة الصحيحة وتكون إما 'A' أو 'B' أو 'C'
};

struct Student {
    string name;
    int id;
    int score;
};

// --- إعلان الدوال (Function Declarations) ---
void initializeQuestions(Question bank[]);
void startExam(const Question bank[], Student& student);
void displayResult(const Student student);

// --- الدالة الرئيسية (Main Function) ---
int main() {
    Question questionBank[TOTAL_QUESTIONS];
    Student currentStudent;

    // 1. تجهيز وتعبئة أسئلة الاختبار في المصفوفة
    initializeQuestions(questionBank);

    cout << "=========================================\n";
    cout << "    Welcome to the Online Exam System    \n";
    cout << "=========================================\n";

    // 2. تسجيل بيانات الطالب
    cout << "Enter Student Name: ";
    // استخدام getline لقراءة الاسم الثنائي أو الثلاثي مع الفراغات
    cin.ignore(); // لتنظيف ذاكرة الإدخال قبل قراءة النصوص
    getline(cin, currentStudent.name);
    
    cout << "Enter Student ID: ";
    cin >> currentStudent.id;
    
    currentStudent.score = 0; // تصفير درجة الطالب عند البداية

    cout << "\nRegistration Successful! Get ready for the exam.\n\n";

    // 3. استدعاء دالة بدء الاختبار
    startExam(questionBank, currentStudent);

    // 4. استدعاء دالة عرض النتيجة النهائية
    displayResult(currentStudent);

    return 0;
}

// --- بناء الدوال (Function Definitions) ---

// دالة لتعبئة مصفوفة الأسئلة
void initializeQuestions(Question bank[]) {
    // السؤال الأول
    bank[0].questionText = "What is the correct syntax to output 'Hello World' in C++?";
    bank[0].optionA = "cout << 'Hello World';";
    bank[0].optionB = "print('Hello World');";
    bank[0].optionC = "echo 'Hello World';";
    bank[0].correctAnswer = 'A';

    // السؤال الثاني
    bank[1].questionText = "Which data type is used to create a variable that should store text?";
    bank[1].optionA = "myString";
    bank[1].optionB = "string";
    bank[1].optionC = "Txt";
    bank[1].correctAnswer = 'B';

    // السؤال الثالث
    bank[2].questionText = "How do you insert COMMENTS in C++ code?";
    bank[2].optionA = "# This is a comment";
    bank[2].optionB = "// This is a comment";
    bank[2].optionC = "/* This is a comment";
    bank[2].correctAnswer = 'B';
}

// دالة إدارة الاختبار وطرح الأسئلة على الطالب
void startExam(const Question bank[], Student& student) {
    char studentAnswer;

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        cout << "-----------------------------------------\n";
        cout << "Question " << (i + 1) << ": " << bank[i].questionText << "\n";
        cout << "A) " << bank[i].optionA << "\n";
        cout << "B) " << bank[i].optionB << "\n";
        cout << "C) " << bank[i].optionC << "\n";
        
        // حلقة تكرار للتأكد من أن الطالب أدخل حرفاً صحيحاً
        do {
            cout << "Your Answer (A, B, or C): ";
            cin >> studentAnswer;
            studentAnswer = toupper(studentAnswer); // تحويل الحرف إلى كابتل لتجنب المشاكل
        } while (studentAnswer != 'A' && studentAnswer != 'B' && studentAnswer != 'C');

        // مقارنة إجابة الطالب بالإجابة الصحيحة للسؤال
        if (studentAnswer == bank[i].correctAnswer) {
            student.score++; // زيادة درجة الطالب إذا كانت الإجابة صحيحة
        }
    }
}

// دالة حساب وعرض التقرير النهائي للطالب
void displayResult(const Student student) {
    cout << "\n=========================================\n";
    cout << "               EXAM RESULT               \n";
    cout << "=========================================\n";
    cout << "Student Name : " << student.name << "\n";
    cout << "Student ID   : " << student.id << "\n";
    cout << "Total Score  : " << student.score << " / " << TOTAL_QUESTIONS << "\n";
    
    // حساب النسبة المئوية (استخدام static_cast لتحويل الأرقام إلى double للحصول على كسور دقيقة)
    double percentage = (static_cast<double>(student.score) / TOTAL_QUESTIONS) * 100;
    cout << "Percentage   : " << percentage << "%\n";

    // تحديد حالة الطالب بناءً على النسبة
    if (percentage >= 50.0) {
        cout << "Status       : PASSED (Congratulations!)\n";
    } else {
        cout << "Status       : FAILED (Better luck next time)\n";
    }
    cout << "=========================================\n";
}
