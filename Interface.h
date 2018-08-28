#if !defined(InterfaceH)
#define InterfaceH

//include standard libraries
#include <string>		//for string
using namespace std;

class Interface {
	public:
		int getKeyPressFromUser() const;
		void drawGridOnScreen(const string& gridData) const ;
		void showResultsOnScreen(string* p_message) const;
		void holdWindow();
};

#endif // !defined(InterfaceH)