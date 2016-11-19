#ifndef PA4_CONFIGURATION_H
#define PA4_CONFIGURATION_H


class Configuration {

	// An abstract class which keeps state/configuration of the model.
	// Implementation of this abstract class depends on the model type.

	public:
		virtual ~Configuration(){};
		virtual void print() const =0;

};

#endif // PA4_CONFIGURATION_H