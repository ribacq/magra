#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QMenuBar>
#include <QTreeView>
#include <QTreeWidgetItem>
#include <QLabel>

// GUI is the root class for all graphical interface.
class GUI : public QWidget {
	// members
	QVBoxLayout *layout = new QVBoxLayout();
	QHBoxLayout *mainLayout = new QHBoxLayout();
	QVBoxLayout *leftVBox = new QVBoxLayout();
	QTabWidget *rightTabs = new QTabWidget();
	QMenuBar *menuBar = new QMenuBar();
	QTreeView *groupsTree = new QTreeView();
	QLabel *currentGroupLabel = new QLabel();

public:
	// constructor
	GUI();
};
