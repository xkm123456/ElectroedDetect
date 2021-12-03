/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 12.0
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HCOMPONENTTRAINING
#define HCPP_HCOMPONENTTRAINING

namespace HalconCpp
{

// Represents an instance of a training result for the component-based matching.
class LIntExport HComponentTraining : public HToolBase
{

public:

  // Create an uninitialized instance
  HComponentTraining():HToolBase() {}

  // Copy constructor
  HComponentTraining(const HComponentTraining& source) : HToolBase(source) {}

  // Create HComponentTraining from handle, taking ownership
  explicit HComponentTraining(Hlong handle);

  // Set new handle, taking ownership
  void SetHandle(Hlong handle);

  // Deep copy of all data represented by this object instance
  HComponentTraining Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // train_model_components: Train components and relations for the component-based matching.
  explicit HComponentTraining(const HImage& ModelImage, const HRegion& InitialComponents, const HImage& TrainingImages, HRegion* ModelComponents, const HTuple& ContrastLow, const HTuple& ContrastHigh, const HTuple& MinSize, const HTuple& MinScore, const HTuple& SearchRowTol, const HTuple& SearchColumnTol, const HTuple& SearchAngleTol, const HString& TrainingEmphasis, const HString& AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold);

  // train_model_components: Train components and relations for the component-based matching.
  explicit HComponentTraining(const HImage& ModelImage, const HRegion& InitialComponents, const HImage& TrainingImages, HRegion* ModelComponents, Hlong ContrastLow, Hlong ContrastHigh, Hlong MinSize, double MinScore, Hlong SearchRowTol, Hlong SearchColumnTol, double SearchAngleTol, const HString& TrainingEmphasis, const HString& AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold);

  // train_model_components: Train components and relations for the component-based matching.
  explicit HComponentTraining(const HImage& ModelImage, const HRegion& InitialComponents, const HImage& TrainingImages, HRegion* ModelComponents, Hlong ContrastLow, Hlong ContrastHigh, Hlong MinSize, double MinScore, Hlong SearchRowTol, Hlong SearchColumnTol, double SearchAngleTol, const char* TrainingEmphasis, const char* AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold);




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Prepare a component model for matching based on trained components.
  HComponentModel CreateTrainedComponentModel(double AngleStart, double AngleExtent, const HTuple& MinContrastComp, const HTuple& MinScoreComp, const HTuple& NumLevelsComp, const HTuple& AngleStepComp, const HString& OptimizationComp, const HTuple& MetricComp, const HTuple& PregenerationComp, HTuple* RootRanking) const;

  // Prepare a component model for matching based on trained components.
  HComponentModel CreateTrainedComponentModel(double AngleStart, double AngleExtent, Hlong MinContrastComp, double MinScoreComp, Hlong NumLevelsComp, double AngleStepComp, const HString& OptimizationComp, const HString& MetricComp, const HString& PregenerationComp, Hlong* RootRanking) const;

  // Prepare a component model for matching based on trained components.
  HComponentModel CreateTrainedComponentModel(double AngleStart, double AngleExtent, Hlong MinContrastComp, double MinScoreComp, Hlong NumLevelsComp, double AngleStepComp, const char* OptimizationComp, const char* MetricComp, const char* PregenerationComp, Hlong* RootRanking) const;

  // Return the relations between the model components that are contained in a training result.
  HRegion GetComponentRelations(Hlong ReferenceComponent, const HTuple& Image, HTuple* Row, HTuple* Column, HTuple* Phi, HTuple* Length1, HTuple* Length2, HTuple* AngleStart, HTuple* AngleExtent) const;

  // Return the relations between the model components that are contained in a training result.
  HRegion GetComponentRelations(Hlong ReferenceComponent, const HString& Image, double* Row, double* Column, double* Phi, double* Length1, double* Length2, double* AngleStart, double* AngleExtent) const;

  // Return the relations between the model components that are contained in a training result.
  HRegion GetComponentRelations(Hlong ReferenceComponent, const char* Image, double* Row, double* Column, double* Phi, double* Length1, double* Length2, double* AngleStart, double* AngleExtent) const;

  // Return the initial or model components in a certain image.
  HRegion GetTrainingComponents(const HTuple& Components, const HTuple& Image, const HString& MarkOrientation, HTuple* Row, HTuple* Column, HTuple* Angle, HTuple* Score) const;

  // Return the initial or model components in a certain image.
  HRegion GetTrainingComponents(const HString& Components, const HString& Image, const HString& MarkOrientation, double* Row, double* Column, double* Angle, double* Score) const;

  // Return the initial or model components in a certain image.
  HRegion GetTrainingComponents(const char* Components, const char* Image, const char* MarkOrientation, double* Row, double* Column, double* Angle, double* Score) const;

  // Modify the relations within a training result.
  void ModifyComponentRelations(const HTuple& ReferenceComponent, const HTuple& ToleranceComponent, const HTuple& PositionTolerance, const HTuple& AngleTolerance) const;

  // Modify the relations within a training result.
  void ModifyComponentRelations(const HString& ReferenceComponent, const HString& ToleranceComponent, double PositionTolerance, double AngleTolerance) const;

  // Modify the relations within a training result.
  void ModifyComponentRelations(const char* ReferenceComponent, const char* ToleranceComponent, double PositionTolerance, double AngleTolerance) const;

  // Deserialize a component training result.
  void DeserializeTrainingComponents(const HSerializedItem& SerializedItemHandle);

  // Serialize a component training result.
  HSerializedItem SerializeTrainingComponents() const;

  // Read a component training result from a file.
  void ReadTrainingComponents(const HString& FileName);

  // Read a component training result from a file.
  void ReadTrainingComponents(const char* FileName);

  // Write a component training result to a file.
  void WriteTrainingComponents(const HString& FileName) const;

  // Write a component training result to a file.
  void WriteTrainingComponents(const char* FileName) const;

  // Adopt new parameters that are used to create the model components into the training result.
  HRegion ClusterModelComponents(const HImage& TrainingImages, const HString& AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold) const;

  // Adopt new parameters that are used to create the model components into the training result.
  HRegion ClusterModelComponents(const HImage& TrainingImages, const char* AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold) const;

  // Inspect the rigid model components obtained from the training.
  HRegion InspectClusteredComponents(const HString& AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold) const;

  // Inspect the rigid model components obtained from the training.
  HRegion InspectClusteredComponents(const char* AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold) const;

  // Train components and relations for the component-based matching.
  HRegion TrainModelComponents(const HImage& ModelImage, const HRegion& InitialComponents, const HImage& TrainingImages, const HTuple& ContrastLow, const HTuple& ContrastHigh, const HTuple& MinSize, const HTuple& MinScore, const HTuple& SearchRowTol, const HTuple& SearchColumnTol, const HTuple& SearchAngleTol, const HString& TrainingEmphasis, const HString& AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold);

  // Train components and relations for the component-based matching.
  HRegion TrainModelComponents(const HImage& ModelImage, const HRegion& InitialComponents, const HImage& TrainingImages, Hlong ContrastLow, Hlong ContrastHigh, Hlong MinSize, double MinScore, Hlong SearchRowTol, Hlong SearchColumnTol, double SearchAngleTol, const HString& TrainingEmphasis, const HString& AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold);

  // Train components and relations for the component-based matching.
  HRegion TrainModelComponents(const HImage& ModelImage, const HRegion& InitialComponents, const HImage& TrainingImages, Hlong ContrastLow, Hlong ContrastHigh, Hlong MinSize, double MinScore, Hlong SearchRowTol, Hlong SearchColumnTol, double SearchAngleTol, const char* TrainingEmphasis, const char* AmbiguityCriterion, double MaxContourOverlap, double ClusterThreshold);

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HToolArrayRef;

typedef HToolArrayRef<HComponentTraining> HComponentTrainingArrayRef;
typedef HSmartPtr< HComponentTrainingArrayRef > HComponentTrainingArrayPtr;


// Represents multiple tool instances
class LIntExport HComponentTrainingArray : public HToolArray
{

public:

  // Create empty array
  HComponentTrainingArray();

  // Create array from native array of tool instances
  HComponentTrainingArray(HComponentTraining* classes, Hlong length);

  // Copy constructor
  HComponentTrainingArray(const HComponentTrainingArray &tool_array);

  // Destructor
  virtual ~HComponentTrainingArray();

  // Assignment operator
  HComponentTrainingArray &operator=(const HComponentTrainingArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HComponentTraining* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HComponentTrainingArrayPtr *mArrayPtr;
};

}

#endif
