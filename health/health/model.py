#import missingno as msno
import numpy as np
import pandas as pd
import seaborn as sns
import warnings
import pickle

warnings.filterwarnings('ignore')
import matplotlib.pyplot as plt
print("Imported all modules")
dataset = pd.read_csv(r"C:\Users\DELL\Downloads\archive (1)\dataset.csv")
print(dataset.head())
Precautions = pd.read_csv(r"C:\Users\DELL\Downloads\archive (1)\symptom_precaution.csv")
severity = pd.read_csv(r"C:\Users\DELL\Downloads\archive (1)\Symptom-severity.csv")

#Removing spaces between words to be able to transform it
def remove_space_between_word(dataset):
    for col in dataset.columns:
        for i in range(len(dataset[col])):
            if (type(dataset[col][i]) == str ):
                dataset[col][i] = dataset[col][i].strip()
                dataset[col][i] = dataset[col][i].replace(" ", "_")
    return dataset
new_df = remove_space_between_word(dataset)
print(new_df.head())

### creating a dictionary of symptoms mapped to keys 
data_dict = severity.set_index('Symptom').T.to_dict()


#Encoding each of the symptoms to its weight 
def encode_data(dataset , data_dict_weigth):
    cols = dataset.columns
    for columnName in cols:
        for i in range(len(dataset[columnName])):
            try:
            #print(data_dict[data2[columnName][i]]["weight"])
                dataset[columnName][i] = data_dict[dataset[columnName][i]]["weight"]
            except:
                pass
    dataset = dataset.fillna(0) # put empty cell to 0
    dataset = dataset.replace("foul_smell_of_urine" , 5)
    dataset = dataset.replace("dischromic__patches" , 6)
    dataset = dataset.replace("spotting__urination" , 6)
    return dataset

df = encode_data(new_df , data_dict)
print(df.head())

## creating the features and the label vectors
X = df.drop(["Disease"],axis=1)

## creating the label vector
Y=df["Disease"]

## splitting the data into train and test data
from sklearn.model_selection import train_test_split
X_train , X_test , Y_train , Y_test  = train_test_split(X,Y,test_size=0.2,random_state=42)
print(X_train.shape, X_test.shape)

from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

from sklearn.svm import SVC
#rbf
svc=SVC(C=100.0) 
svc.fit(X_train,Y_train)
y_pred=svc.predict(X_test)

pickle.dump(svc, open('model.pkl','wb'))

# Loading model to compare the results
model = pickle.load(open('model.pkl','rb'))
print(model.predict(["abnormal_menstruation","acidity","acute_liver_failure"]))
