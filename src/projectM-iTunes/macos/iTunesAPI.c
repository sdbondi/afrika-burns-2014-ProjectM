/*
     File:       iTunesAPI.c
 
     Contains:   iTunes Plug-ins interfaces
 
     Version:    Technology: iTunes
                 Release:    1.1
 
     Copyright:  � 2001 by Apple Computer, Inc., all rights reserved.
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#include "iTunesAPI.h"
#include "iTunesVisualAPI.h"

// MemClear
//
static void MemClear (LogicalAddress dest, SInt32 length)
{
	register unsigned char	*ptr;

	ptr = (unsigned char *) dest;
	
	if( length > 16 )
	{
		register unsigned long	*longPtr;
		
		while( ((unsigned long) ptr & 3) != 0 )
		{
			*ptr++ = 0;
			--length;
		}
		
		longPtr = (unsigned long *) ptr;
		
		while( length >= 4 )
		{
			*longPtr++ 	= 0;
			length		-= 4;
		}
		
		ptr = (unsigned char *) longPtr;
	}
	
	while( --length >= 0 )
	{
		*ptr++ = 0;
	}
}


// SetNumVersion
//
void SetNumVersion (NumVersion *numVersion, UInt8 majorRev, UInt8 minorAndBugRev, UInt8 stage, UInt8 nonRelRev)
{
	numVersion->majorRev		= majorRev;
	numVersion->minorAndBugRev	= minorAndBugRev;
	numVersion->stage			= stage;
	numVersion->nonRelRev		= nonRelRev;
}


// ITCallApplication
//
OSStatus ITCallApplication (void *appCookie, ITAppProcPtr handler, OSType message, PlayerMessageInfo *messageInfo)
{
	PlayerMessageInfo	localMessageInfo;
	
	if (messageInfo == nil)
	{
		MemClear(&localMessageInfo, sizeof(localMessageInfo));
		
		messageInfo = &localMessageInfo;
	}
	
	messageInfo->messageMajorVersion = kITCurrentPluginMajorMessageVersion;
	messageInfo->messageMinorVersion = kITCurrentPluginMinorMessageVersion;
	messageInfo->messageInfoSize	 = sizeof(PlayerMessageInfo);
	
	return handler(appCookie, message, messageInfo);
}


// PlayerSetFullScreen
//
OSStatus PlayerSetFullScreen (void *appCookie, ITAppProcPtr appProc, Boolean fullScreen)
{
	PlayerMessageInfo	messageInfo;
	
	MemClear(&messageInfo, sizeof(messageInfo));
	
	messageInfo.u.setFullScreenMessage.fullScreen = fullScreen;

	return ITCallApplication(appCookie, appProc, kPlayerSetFullScreenMessage, &messageInfo);
}


// PlayerSetFullScreenOptions
//
OSStatus PlayerSetFullScreenOptions (void *appCookie, ITAppProcPtr appProc, SInt16 minBitDepth, SInt16 maxBitDepth, SInt16 preferredBitDepth, SInt16 desiredWidth, SInt16 desiredHeight)
{
	PlayerMessageInfo	messageInfo;
	
	MemClear(&messageInfo, sizeof(messageInfo));
	
	messageInfo.u.setFullScreenOptionsMessage.minBitDepth		= minBitDepth;
	messageInfo.u.setFullScreenOptionsMessage.maxBitDepth		= maxBitDepth;
	messageInfo.u.setFullScreenOptionsMessage.preferredBitDepth = preferredBitDepth;
	messageInfo.u.setFullScreenOptionsMessage.desiredWidth		= desiredWidth;
	messageInfo.u.setFullScreenOptionsMessage.desiredHeight		= desiredHeight;

	return ITCallApplication(appCookie, appProc, kPlayerSetFullScreenOptionsMessage, &messageInfo);
}


// PlayerGetPluginData
//
OSStatus PlayerGetPluginData (void *appCookie, ITAppProcPtr appProc, void *dataPtr, UInt32 dataBufferSize, UInt32 *dataSize)
{
	OSStatus			status;
	PlayerMessageInfo	messageInfo;
	
	MemClear(&messageInfo, sizeof(messageInfo));
	
	messageInfo.u.getPluginDataMessage.dataPtr			= dataPtr;
	messageInfo.u.getPluginDataMessage.dataBufferSize	= dataBufferSize;
	
	status = ITCallApplication(appCookie, appProc, kPlayerGetPluginDataMessage, &messageInfo);
	
	if (dataSize != nil)
		*dataSize = messageInfo.u.getPluginDataMessage.dataSize;
	
	return status;
}


// PlayerSetPluginData
//
OSStatus PlayerSetPluginData (void *appCookie, ITAppProcPtr appProc, void *dataPtr, UInt32 dataSize)
{
	PlayerMessageInfo	messageInfo;
	
	MemClear(&messageInfo, sizeof(messageInfo));
	
	messageInfo.u.setPluginDataMessage.dataPtr	= dataPtr;
	messageInfo.u.setPluginDataMessage.dataSize	= dataSize;
	
	return ITCallApplication(appCookie, appProc, kPlayerSetPluginDataMessage, &messageInfo);
}


// PlayerGetPluginNamedData
//
OSStatus PlayerGetPluginNamedData (void *appCookie, ITAppProcPtr appProc, ConstStringPtr dataName, void *dataPtr, UInt32 dataBufferSize, UInt32 *dataSize)
{
	OSStatus			status;
	PlayerMessageInfo	messageInfo;
	
	MemClear(&messageInfo, sizeof(messageInfo));
	
	messageInfo.u.getPluginNamedDataMessage.dataName		= dataName;
	messageInfo.u.getPluginNamedDataMessage.dataPtr			= dataPtr;
	messageInfo.u.getPluginNamedDataMessage.dataBufferSize	= dataBufferSize;
	
	status = ITCallApplication(appCookie, appProc, kPlayerGetPluginNamedDataMessage, &messageInfo);
	
	if (dataSize != nil)
		*dataSize = messageInfo.u.getPluginNamedDataMessage.dataSize;
	
	return status;
}


// PlayerSetPluginNamedData
//
OSStatus PlayerSetPluginNamedData (void *appCookie, ITAppProcPtr appProc, ConstStringPtr dataName, void *dataPtr, UInt32 dataSize)
{
	PlayerMessageInfo	messageInfo;
	
	MemClear(&messageInfo, sizeof(messageInfo));
	
	messageInfo.u.setPluginNamedDataMessage.dataName	= dataName;
	messageInfo.u.setPluginNamedDataMessage.dataPtr		= dataPtr;
	messageInfo.u.setPluginNamedDataMessage.dataSize	= dataSize;
	
	return ITCallApplication(appCookie, appProc, kPlayerSetPluginNamedDataMessage, &messageInfo);
}


// PlayerIdle
//
OSStatus PlayerIdle (void *appCookie, ITAppProcPtr appProc)
{
	return ITCallApplication(appCookie, appProc, kPlayerIdleMessage, nil);
}


// PlayerShowAbout
//
void PlayerShowAbout (void *appCookie, ITAppProcPtr appProc)
{
	ITCallApplication(appCookie, appProc, kPlayerShowAboutMessage, nil);
}


// PlayerOpenURL
//
void PlayerOpenURL (void *appCookie, ITAppProcPtr appProc, SInt8 *string, UInt32 length)
{
	PlayerMessageInfo	messageInfo;
	
	MemClear(&messageInfo, sizeof(messageInfo));
	
	messageInfo.u.openURLMessage.url	= string;
	messageInfo.u.openURLMessage.length	= length;

	ITCallApplication(appCookie, appProc, kPlayerOpenURLMessage, &messageInfo);
}

// PlayerUnregisterPlugin
//
OSStatus PlayerUnregisterPlugin (void *appCookie, ITAppProcPtr appProc, PlayerMessageInfo *messageInfo)
{
	return ITCallApplication(appCookie, appProc, kPlayerUnregisterPluginMessage, messageInfo);
}


// PlayerRegisterVisualPlugin
//
OSStatus PlayerRegisterVisualPlugin (void *appCookie, ITAppProcPtr appProc, PlayerMessageInfo *messageInfo)
{			
	return ITCallApplication(appCookie, appProc, kPlayerRegisterVisualPluginMessage, messageInfo);
}

// PlayerRegisterDevicePlugin
//
OSStatus PlayerRegisterDevicePlugin (void *appCookie, ITAppProcPtr appProc, PlayerMessageInfo *messageInfo)
{			
	return ITCallApplication(appCookie, appProc, kPlayerRegisterDevicePluginMessage, messageInfo);
}


// PlayerSetDeviceSerialNumber
//
OSStatus PlayerSetDeviceSerialNumber (void *appCookie, ITAppProcPtr appProc, ConstStringPtr serialNumber)
{
	PlayerMessageInfo	messageInfo;
	
	MemClear(&messageInfo, sizeof(messageInfo));
	
	messageInfo.u.setDeviceSerialNumberMessage.serialNumber = serialNumber;
	
	return ITCallApplication(appCookie, appProc, kPlayerSetDeviceSerialNumberMessage, &messageInfo);
}




// PlayerHandleMacOSEvent
//
OSStatus PlayerHandleMacOSEvent (void *appCookie, ITAppProcPtr appProc, const EventRecord *theEvent, Boolean *eventHandled)
{
	PlayerMessageInfo	messageInfo;
	OSStatus			status;
	
	MemClear(&messageInfo, sizeof(messageInfo));
	
	messageInfo.u.handleMacOSEventMessage.theEvent = theEvent;
		
	status = ITCallApplication(appCookie, appProc, kPlayerHandleMacOSEventMessage, &messageInfo);
	
	if( eventHandled != nil )
		*eventHandled = messageInfo.u.handleMacOSEventMessage.handled;
	
	return status;
}


// PlayerGetPluginFileSpec
//
OSStatus PlayerGetPluginFileSpec (void *appCookie, ITAppProcPtr appProc, FSSpec *pluginFileSpec)
{
	PlayerMessageInfo	messageInfo;
	
	MemClear(&messageInfo, sizeof(messageInfo));
	
	messageInfo.u.getPluginFileSpecMessage.fileSpec = pluginFileSpec;
	
	return ITCallApplication(appCookie, appProc, kPlayerGetPluginFileSpecMessage, &messageInfo);
}