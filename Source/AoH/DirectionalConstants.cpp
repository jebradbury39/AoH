#include "DirectionalConstants.h"

const int UNSHIFTED_DIRECTIONS[6][2] = {
	{ 0, -1 },
	{ -1, 0 },
	{ -1, -1 },
	{ 1, 0 },
	{ 1, -1 },
	{ 0, 1 }
};

const int SHIFTED_DIRECTIONS[6][2] = {
	{ 0, -1 },
	{ -1, 1 },
	{ -1, 0 },
	{ 1, 1 },
	{ 1, 0 },
	{ 0, 1 }
};