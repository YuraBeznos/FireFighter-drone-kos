#pragma once

namespace connections {

constexpr const char* FPSHost = "192.168.8.8";

constexpr const char* Aggregation = "aggregation";
constexpr const char* AggregationService = "AggregationCoordinates.coordinates";

constexpr const char* CCU = "ccu";
constexpr const char* CCUService = "CCUActions.actions";

constexpr const char* Communication = "communication";
constexpr const char* CommunicationService = "CommunicationOutside.startedat";

constexpr const char* Extinguishing = "extinguishing";
constexpr const char* ExtinguishingService = "ExtinguishingActions.actions";

constexpr const char* EAIC = "eaic";
constexpr const char* EAICService = "EAICActions.actions";

constexpr const char* FMAC = "fmac";
constexpr const char* FMACService = "FMACActions.actions";

constexpr const char* Movement = "movement";
constexpr const char* MovementService = "MovementActions.actions";

constexpr const char* Navigation = "navigation";
constexpr const char* NavigationService = "NavigationCoordinates.coordinates";

constexpr const char* Situation = "situation";
constexpr const char* SituationService = "SituationActions.actions";

} // namespace connections
