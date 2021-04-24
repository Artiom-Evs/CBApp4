#pragma once

using namespace System;
using namespace System::Net;
using namespace System::Net::Http;
using namespace System::Threading::Tasks;
using namespace ParserApp::Models;
using namespace ParserApp::Services;

namespace CBApp4
{
    public delegate void DataLoadingEventHandler();

    ref class DataController
    {
    private:
        String^ groupsAddress;
        String^ teachersAddress;
        EntitiesList^ _groups;
        EntitiesList^ _teachers;
        HttpClient^ httpClient;

        Task^ _loading;

        void LoadingData() {
            Task<String^>^ taskGroupsLoading = this->httpClient->GetStringAsync(this->groupsAddress);
            Task<String^>^ taskTeachersLoading = this->httpClient->GetStringAsync(this->teachersAddress);
            this->_groups = Parser::ParsePage(taskGroupsLoading, true);
            this->_teachers = Parser::ParsePage(taskTeachersLoading, false);

            this->OnDataLoaded();
        }
        Void groups_DownloadStringCompleted(Object^ sender, DownloadStringCompletedEventArgs^ e)
        {
            this->_groups = ParserApp::Services::Parser::ParsePage(e->Result, true);
        }
        Void teachers_DownloadStringCompleted(Object^ sender, DownloadStringCompletedEventArgs^ e)
        {
            this->_teachers = ParserApp::Services::Parser::ParsePage(e->Result, true);
        }

        void OnDataLoaded() {
            this->DataLoadingCompleted();
        }

    public:
        DataController() {
            this->groupsAddress = gcnew String("http://mgke.minsk.edu.by/ru/main.aspx?guid=3791");
            this->teachersAddress = gcnew String("http://mgke.minsk.edu.by/ru/main.aspx?guid=3811");

            System::Net::ServicePointManager::DefaultConnectionLimit = 4;
            this->httpClient = gcnew HttpClient();
        }

        property EntitiesList^ Groups {
            EntitiesList^ get() {
                return this->_groups;
            }
        }
        property EntitiesList^ Teachers {
            EntitiesList^ get() {
                return this->_teachers;
            }
        }
        property Task^ Loading {
            Task^ get() {
                return this->_loading;
            }
        }

        void StartLoading() {
            this->_loading = Task::Run(gcnew Action(this, &DataController::LoadingData));
        }
        Void Old_StartLoading()
        {
            WebClient^ client1 = gcnew WebClient;
            WebClient^ client2 = gcnew WebClient;
            client1->DownloadStringCompleted += gcnew DownloadStringCompletedEventHandler(this, &DataController::groups_DownloadStringCompleted);
            client2->DownloadStringCompleted += gcnew DownloadStringCompletedEventHandler(this, &DataController::teachers_DownloadStringCompleted);
            client1->DownloadStringAsync(gcnew Uri(this->groupsAddress));
            client2->DownloadStringAsync(gcnew Uri(this->teachersAddress));
        }

        event DataLoadingEventHandler^ DataLoadingCompleted;
    };

}






/*
using namespace CBApp3::Domain::Services;
using namespace Models;
namespace Models
{
    ref class Day
    {
    private:
        String^ _date;
        List<array<String^>^>^ _lessons;

    public:
        Day()
        {
            this->_date = "";
            this->_lessons = gcnew List<array<String^>^>();
        }

        Day(String^ name)
        {
            this->_date = name;
            this->_lessons = gcnew List<array<String^>^>();
        }

        Day(String^ name, List<array<String^>^>^ lessons)
        {
            this->_date = name;
            this->_lessons = lessons;
        }

        property String^ Date
        {
            String^ get()
            {
                return this->_date;
}
            Void set(String^ value)
            {
                this->_date = value;
            }
        }

        property List<array<String^>^>^ Lessons
        {
            List<array<String^>^>^ get()
            {
                return this->_lessons;
            }
            Void set(List<array<String^>^>^ value)
            {
                this->_lessons = value;
            }
        }

        String^ ToString() override
        {
            return this->Date;
        }
    };

    ref class Entity
    {
    private:
        String^ _name;
        String^ _date;
        int _number;
        List<Day^>^ _days;

    public:
        Entity()
        {
            this->_name = "";
            this->_date = "";
            this->_number = 0;
            this->_days = gcnew List<Day^>();
        }

        property String^ Name
        {
            String^ get()
            {
                return this->_name;
            }
            void set(String^ value)
            {
                this->_name = value;
            }
        }

        property String^ Date
        {
            String^ get()
            {
                return this->_date;
            }
            void set(String^ value)
            {
                this->_date;
            }
        }

        property int Number
        {
            int get()
            {
                return this->_number;
            }
            void set(int value)
            {
                this->_number;
            }
        }

        property List<Day^>^ Days
        {
            List<Day^>^ get()
            {
                return this->_days;
            }
            void set(List<Day^>^ value)
            {
                this->_days = value;
            }
        }

        String^ ToString() override
        {
            return this->_name;
        }
    };

    ref class EntitiesList
    {
    private:
        String^ _name;
        String^ _date;
        bool _isGroup;
        List<Entity^>^ _entities;

    public:
        property String^ Name
        {
            String^ get()
            {
                return this->_name;
            }
            void set(String^ value)
            {
                this->_name = value;
            }
        }

        property String^ Date
        {
            String^ get()
            {
                return this->_date;
            }
            void set(String^ value)
            {
                this->_date;
            }
        }

        property bool IsGroup
        {
            bool get()
            {
                return this->_isGroup;
            }
            void set(bool value)
            {
                this->_isGroup;
            }
        }

        property List<Entity^>^ Days
        {
            List<Entity^>^ get()
            {
                return this->_entities;
            }
            void set(List<Entity^>^ value)
            {
                this->_entities = value;
            }
        }

        EntitiesList()
        {
            this->_name = "";
            this->_date = "";
            this->_isGroup = true;
            this->_entities = gcnew List<Entity^>();
        }

        EntitiesList(bool isGroup, String^ name, String^ date)
        {
            this->_name = name;
            this->_date = date;
            this->_isGroup = isGroup;
            this->_entities = gcnew List<Entity^>();
        }

        String^ ToString() override
        {
            return this->_date;
        }
    };
}

namespace Services
{
    static ref class Parser
    {
    public:
        static Models::EntitiesList^ ParsePage(Task<String^>^ pageText, bool isGroup)
        {
            return Parser::ParsePage(pageText, isGroup);
        }

        static Models::EntitiesList^ ParsePage(String^ pageText, bool isGroup)
        {
            return Parser::ParsePage(pageText, isGroup);
        }
    };

    ref class DataController
    {
    private:
        EntitiesList^ source;
        String^ address;
        bool isGroup;

    public:
        DataController(EntitiesList^ source, String^ address, bool isGroup)
        {
            this->source = source;
            this->address = address;
            this->isGroup = isGroup;
        }

        property EntitiesList^ Source
        {
            EntitiesList^ get()
            {
                return this->source;
            }
            void set(EntitiesList^ value)
            {
                this->source = value;
            }
        }
    };
}
*/