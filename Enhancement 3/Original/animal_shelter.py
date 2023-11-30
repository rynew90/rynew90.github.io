# -*- coding: utf-8 -*-
from pymongo import MongoClient
from bson.objectid import ObjectId

class AnimalShelter(object):
    """ CRUD operations for Animal collection in MongoDB """

    def __init__(self, USER, PASS):
        # Initializing the MongoClient. This helps to 
        # access the MongoDB databases and collections.
        # This is hard-wired to use the aac database, the 
        # animals collection, and the aac user.
        # Definitions of the connection string variables are
        # unique to the individual Apporto environment.
        #
        # You must edit the connection variables below to reflect
        # your own instance of MongoDB!
        #
        # Connection Variables
        #
        #USER = 'aacuser'
        #PASS = 'pass'
        HOST = 'nv-desktop-services.apporto.com'
        PORT = 30022
        DB = 'aac'
        COL = 'animals'
        #
        # Initialize Connection
        #
        self.client = MongoClient('mongodb://%s:%s@%s:%d' % (USER,PASS,HOST,PORT))
        self.database = self.client['%s' % (DB)]
        self.collection = self.database['%s' % (COL)]
        print ("Connection Successful")

    def create(self, data):
        if data is not None:
            self.database.animals.insert_one(data)  # data should be dictionary
            return True
        
        else:
            raise Exception("Nothing to save, because data parameter is empty")
            return Exception
            
    def read(self, data = None):
        if data is not None:
            result = self.database.animals.find(data)
            return result
        
        else:
            raise Exception("Nothing to find, because data parameter is empty")
            return Exception
        
    def update(self, data, new_data):
        if data is not None:
            modify = self.database.animals.update_one(data, {"$set": new_data})
            return modify
        
        else:
            raise Exception("Nothing to update, because data parameter is empty")
            return Exception
        
    def delete(self, data):
        if data is not None:
            remove = self.database.animals.delete_one(data)
            return remove
        
        else:
            raise Exception("Nothing to delete, because data parameter is empty")
            return Exception
        
