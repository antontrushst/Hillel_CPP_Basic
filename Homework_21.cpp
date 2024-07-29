/*
    1. Необхідні класи та об'єкти:
        - class Road
            * object Road_1
            * object Road_2

        - class Vehicle
            * object Car_01
            * object Car_02
            * ...

        - class Pedestrian
            * object Pedestrian_01
            * object Pedestrian_02
            * ...

        - class TrafficLights
            * object TrafficLights
            
--------------------------------------------------------------------------------
    2. Модель зміниться наступним чином:
        - class Road
            * object Road_1
            * object Road_2

        - class Vehicle
            - class Taxi
                * object Taxi_01
                * object Taxi_02
                * ...
            - class CitizenCar
                * object CitizenCar_01
                * object CitizenCar_02
                * ...
            - class NonCitizenCar
                * object NonCitizenCar_01
                * object nonCitizenCar_02
                * ...

        - class Pedestrian
            - class Citizen
                * object Citizen_01
                * object Citizen_02
                * ...
            - class NonCitizen
                * object NonCitizen_01
                * object NonCitizen_02
                * ...

        - class TrafficLights
            * object TrafficLights

--------------------------------------------------------------------------------
    3. Основні підсистеми:
        - календар-планувальник
        - букінг номерів
*/


//  4. Інтерфейси для програми з вправи 3. Система використовує функціонал
//     дружніх класів для можливості керування об'єктами Event та BookedRoom
//     виключно в рамках методів класів-систем Scheduler та Booking.

#include <string>
#include <vector>

class Scheduler
{
public:
    virtual void  MakeCalendar() const = 0;
    virtual void  AddEvent() = 0;
    virtual void  DeleteEvent() = 0;
    virtual void  ChangeEvent() = 0;
    virtual Event GetEvent() const = 0;

private:
    std::vector<Event> itsEvents;
};

class Event
{
friend class Scheduler;

private:
    std::string itsName;
    std::string itsLocation;
    std::string itsDescription;
    short itsDay;
    short itsMonth;
    short itsYear;
    short itsHours;
    short itsMinutes;
    short itsDurationHours;
    short itsDurationMinutes;
    std::vector<std::string> itsParticipants;

    Event();
};

class Booking
{
public:
    virtual void UpdateHotelList() = 0;
    virtual void BookRoom() = 0;
    virtual void CancelBooking() = 0;
    virtual BookedRoom GetBooked() const = 0;

private:
    std::vector<BookedRoom>  itsRooms;
    std::vector<std::string> itsHotelList;
};

class BookedRoom
{
    friend class Booking;

private:
    short itsNumber;
    std::string itsHotel;
    std::string itsDescription;

    BookedRoom();
};