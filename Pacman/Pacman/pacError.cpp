#include "pacError.h"


pac::Message  pac::TranslateResult(Result msg)
{
	Message message;

	switch (msg)
	{
	case FAILURE: message.msg = "Undefined exit failure"; break;
	case SUCCESS: message.msg = "Exit success."; break;
	}

	return message;
}
