
#include "PlasmaPulsePattern.h"

PlasmaPulsePattern::PlasmaPulsePattern(LedChain *chain, RGB_t colour)
: Pattern(chain),
_finalColour(colour),
_time(0),
_position(0)
{

}

void PlasmaPulsePattern::Logic(unsigned int deltaT)
{
	const unsigned int chargeLength = 1000;
	const unsigned int fireLength = 400;
	const unsigned int period = chargeLength + fireLength;

	_time += deltaT;
	if (_time > period) _time = 0;

	// Pattern is as follows:
	// 1: Pulse charges up
	// 2: Pulse moves along the chain, fading out as it goes

	if (_time < chargeLength) {
		// Pulse is charging
		_currentColour = { _time/4, _time/4, _time/4 };
		_position = 0;
	}
	else {
		// Pulse is firing
		_position += 5;
	}
}

void PlasmaPulsePattern::Render()
{
	_chain->Clear();
	_chain->SetPixel(0 + _position, _currentColour);
	_chain->SetPixel(1 + _position, _currentColour);
	_chain->SetPixel(2 + _position, _currentColour);
	_chain->SetPixel(3 + _position, _currentColour);
	_chain->SetPixel(4 + _position, _currentColour);
}

PlasmaPulsePattern::~PlasmaPulsePattern()
{ }
