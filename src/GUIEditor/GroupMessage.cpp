#include "precompiled.h"
#include "GroupMessage.h"

INSTANCE_IMPLEMENT(GroupMessage)

void GroupMessage::AddMessage(const GUI::UString & message, GUI::LogManager::LogLevel type)
{
	if (type == GUI::LogManager::Error)
		mErrorMessages.push_back(message);
	else /*if (type == GUI::LogManager::Warning)*/
		mWarningMessages.push_back(message);
}

void GroupMessage::ShowMessages()
{
	if (mWarningMessages.size())
	{
		GUI::UString warningMess;
		for (GUI::VectorString::iterator iter = mWarningMessages.begin(); iter != mWarningMessages.end(); ++iter)
		{
			if (warningMess.empty()) warningMess = warningMess + *iter;
			else warningMess = warningMess + "\n" + *iter;
		}
		if (!warningMess.empty())
			GUI::Message::CreateMessageBox("Message", GUI::Localise("Warning"), warningMess, GUI::MessageBoxStyle::IconWarning | GUI::MessageBoxStyle::Ok);

		mWarningMessages.clear();
	}

	if (mErrorMessages.size())
	{
		GUI::UString errorMessages;
		for (GUI::VectorString::iterator iter = mErrorMessages.begin(); iter != mErrorMessages.end(); ++iter)
		{
			if (errorMessages.empty()) errorMessages = errorMessages + *iter;
			else errorMessages = errorMessages + "\n" + *iter;
		}
		if (!errorMessages.empty())
			GUI::Message::CreateMessageBox("Message", GUI::Localise("Error"), errorMessages , GUI::MessageBoxStyle::IconError | GUI::MessageBoxStyle::Ok);

		mErrorMessages.clear();
	}
}
