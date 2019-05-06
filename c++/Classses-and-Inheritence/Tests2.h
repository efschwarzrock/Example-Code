/*
 * Tests2.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Erich Schwarzrock
 */

#ifndef TESTS2_H_
#define TESTS2_H_

class Tests2 {
public:
	Tests2();
	bool doTests();
	bool gridTest();
	bool makeAntsTest();
	bool antsMoveTest();
	bool antsBreedTest();
	bool antsDieTest();
	bool makeDoodlesTest();
	bool doodleMoveTest();
	bool doodleBreedTest();
	bool doodleEatTest();
	bool doodleDietest();


	virtual ~Tests2();
};

#endif /* TESTS2_H_ */
