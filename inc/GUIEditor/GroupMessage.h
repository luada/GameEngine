#ifndef __GROUP_MESSAGE__
#define __GROUP_MESSAGE__

class GroupMessage
{
public:
	INSTANCE_HEADER(GroupMessage)

	void AddMessage(const GUI::UString & message, GUI::LogManager::LogLevel type);
	void ShowMessages();
private:
	GUI::VectorString mErrorMessages;
	GUI::VectorString mWarningMessages;
};

#endif // __GROUP_MESSAGE__
