#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Observer Interface
class Observer
{
public:
    virtual void notify(const string& message) = 0;
    virtual ~Observer() {}
};

// Email Notification
class EmailNotification : public Observer
{
private:
    string email;

public:
    EmailNotification(string e)
    {
        email = e;
    }

    void notify(const string& message) override
    {
        cout << "Email sent to "
             << email << ": "
             << message << endl;
    }
};

// SMS Notification
class SMSNotification : public Observer
{
private:
    string phoneNumber;

public:
    SMSNotification(string number)
    {
        phoneNumber = number;
    }

    void notify(const string& message) override
    {
        cout << "SMS sent to "
             << phoneNumber << ": "
             << message << endl;
    }
};

// Push Notification
class PushNotification : public Observer
{
private:
    string device;

public:
    PushNotification(string d)
    {
        device = d;
    }

    void notify(const string& message) override
    {
        cout << "Push Notification sent to "
             << device << ": "
             << message << endl;
    }
};

// Factory Class
class NotificationFactory
{
public:
    static shared_ptr<Observer>
    createNotification(
        const string& type,
        const string& receiver)
    {
        if (type == "EMAIL")
        {
            return make_shared<EmailNotification>(receiver);
        }
        else if (type == "SMS")
        {
            return make_shared<SMSNotification>(receiver);
        }
        else if (type == "PUSH")
        {
            return make_shared<PushNotification>(receiver);
        }

        return nullptr;
    }
};

// Singleton Event Manager
class EventManager
{
private:
    vector<shared_ptr<Observer>> observers;

    EventManager() {}

public:
    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;

    static EventManager& getInstance()
    {
        static EventManager instance;
        return instance;
    }

    void subscribe(shared_ptr<Observer> observer)
    {
        observers.push_back(observer);
    }

    void triggerEvent(const string& message)
    {
        cout << "\nEvent Triggered: "
             << message << endl;

        cout << "Sending Notifications...\n";

        for (auto observer : observers)
        {
            observer->notify(message);
        }
    }
};

int main()
{
    EventManager& manager =
        EventManager::getInstance();

    auto emailUser =
        NotificationFactory::createNotification(
            "EMAIL",
            "john@college.edu");

    auto smsUser =
        NotificationFactory::createNotification(
            "SMS",
            "9123456780");

    auto pushUser =
        NotificationFactory::createNotification(
            "PUSH",
            "StudentPortal");

    manager.subscribe(emailUser);
    manager.subscribe(smsUser);
    manager.subscribe(pushUser);

    manager.triggerEvent(
        "Placement training session at 10 AM.");

    return 0;
}