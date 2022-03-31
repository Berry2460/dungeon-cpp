#pragma once

enum itemQuality: unsigned char {
	INFERIOR,
	NORMAL,
	SUPERIOR,
	MAGIC,
};

enum equipType: unsigned char {
	HELM,
	ARMOR,
	WEAPON1H,
	WEAPON2H,
	SHIELD,
	RING
};

class Item{
	public:
		Item();
		~Item();
	private:
		char *name;
		unsigned char dur;
		unsigned char durMax;
		enum equipType type;
		enum itemQuality quality;
		unsigned char value1;
		unsigned char value2;
		unsigned char magicMod1;
		unsigned char magicMod2;
};
