#ifndef DRIVESTRATEGY_H
#define DRIVESTRATEGY_H

class DriveStrategy {
public:
	virtual ~DriveStrategy() {
	}
	virtual void drive() const = 0;
	virtual DriveStrategy* clone() const = 0;
};

#endif
