#ifndef _GAMECOMMAND_H_
#define _GAMECOMMAND_H_

#include <src/servers/Server_Common/Common.h>

#include "src/servers/Server_Zone/Actor/Player.h"
#include "src/servers/Server_Zone/Forwards.h"

namespace Core {

   class DebugCommandHandler;

   // CGameCommand is used to define in game text command callbacks
   // TODO it should probably be renamed to something more intuitive
   // TODO the command identifier, currently '@' should probably be defined in here aswell so it is easily replaced
   class DebugCommand
   { 
   public:

      typedef void ( DebugCommandHandler::*pFunc )( char *, Entity::PlayerPtr, boost::shared_ptr< DebugCommand > );

      // String for the command
      std::string m_commandName;

      // command callback
      pFunc m_pFunc;

      // helptext 
      std::string m_helpText; 

      // userlevel needed to execute the command
      Common::UserLevel m_userLevel;

      DebugCommand( const std::string& n, pFunc functionPtr, const std::string& hText, Common::UserLevel uLevel )
      {
         m_commandName = n;
         m_pFunc = functionPtr;
         m_helpText = hText;
         m_userLevel = uLevel;
      }

      ~DebugCommand()
      {

      }

      const std::string& getName() const
      {
         return m_commandName;
      }

      const std::string& getHelpText() const
      {
         return m_helpText;
      }

      Common::UserLevel getUserLevel() const
      {
         return m_userLevel;
      }

   };

}


#endif
