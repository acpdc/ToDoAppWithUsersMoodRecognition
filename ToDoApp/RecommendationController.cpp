
#include "RecommendationController.h"
//void sort...()	
//{
//	//Sort task list via task->mood->rating
//}

vector<Task*> propositions;

class RecommendationController::checkTaskPassing
{
public:
	double rating;
	checkTaskPassing(double rat) : rating(rat){}
	void operator() (Task*& task) const
	{
		double delta = abs( task->getMood()->getRating() - rating );
		Task* newTask = task;
		if (delta < 1)  propositions.emplace_back(newTask);
	}
};

double ratingToCheck;
bool  RecommendationController::myComparision(Task* t1, Task* t2) {

	return ( abs(t1->getMood()->getRating() - ratingToCheck) < abs(t2->getMood()->getRating() - ratingToCheck) );
	//return ( t1->getDeadline() < t2->getDeadline() );
}

void RecommendationController::recommend(int moodIndex) {

	Mood* mood = theDataBase->getMood(moodIndex);

	double rating = mood->getRating();

	theDataBase->getTasksList();

	ranges::for_each(theDataBase->getTasksList(), checkTaskPassing(rating));

	ratingToCheck = rating;
	//std::sort(propositions.begin(), propositions.end(), myComparision);

	for (int i = 0; i < 2 && i < propositions.size(); i++) {
		cout << i + 1 << ".\n" << propositions[i]->getTitle() << "\n" << propositions[i]->getDetails() << "\n";
	}
	if (propositions.size() == 0) cout << "Sorry, there is no task matching your mood\n";
	//cout << "Tu polecane taski - 3? 1? \n";

}